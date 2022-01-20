#include "CGAOptimizer.h"

CGAOptimizer::CGAOptimizer() {
	i_popSize = SIZE_OF_POP;
	d_xProbability = CROSS_PROBABILTY;
	d_mutProbability = MUTATION_PROBABILITY;
	vPopulation = new vector<CGAIndividual*>;
	(*vPopulation).reserve(i_popSize+1);
	newVPop = new vector<CGAIndividual*>;
	(*newVPop).reserve(i_popSize + 1);
	pc_Max3SatProblem = NULL;
	rodzic1 = NULL;
	rodzic2 = NULL;
	dziecko1 = NULL;
	dziecko2 = NULL;
	cout << "CGAOptimizer() - DEFAULT PROPERTIES (BEST ONE)" << endl << "i_popSize =" << i_popSize << endl << "d_xProbability ="<< d_xProbability << endl << "d_mutProbability ="<< d_mutProbability << endl;

}

CGAOptimizer::~CGAOptimizer(){
	cout << "Destruktor ~CGAOptimizer()" << endl;

	for (int i = 0; i < (int)(*vPopulation).size(); i++) {
		if ((*vPopulation).at(i) != NULL) {
			delete (*vPopulation).at(i);
		}
	}
	(*vPopulation).clear();
	if (pc_Max3SatProblem != NULL) {
		delete pc_Max3SatProblem;
	}
	if (vPopulation != NULL) {
		delete vPopulation;
	}
	if (newVPop != NULL) {
		delete newVPop;
	}

}

void CGAOptimizer::vInitialize(string sPath) {
	pc_Max3SatProblem = new CMax3SatProblem();
	pc_Max3SatProblem->bLoad(sPath);
	srand((int)time(NULL));
	for (int i = 0; i < i_popSize; i++) {
		(*vPopulation).push_back(new CGAIndividual());
		(*vPopulation).at(i)->vInitializeGenotype(*pc_Max3SatProblem);
	}
}

void CGAOptimizer::vRunIteration()
{	
	for (int i = 0; i < (int)((*vPopulation).size() * ELITISM_PERCENTAGE) ; i++) {
		CGAIndividual* temp = new CGAIndividual((*vPopulation).at(i));
		(*newVPop).push_back(temp);
	}
	

	while ((*newVPop).size() < (*vPopulation).size()) {

		rodzic1 = pc_ChooseParent(); 
		rodzic2 = pc_ChooseParent();  

		int iDoCrossover = rand() % 100;
		if (iDoCrossover < (int) (d_xProbability*100.0)) {
			dziecko1 = new CGAIndividual;
			dziecko2 = new CGAIndividual;
			rodzic1->pcCrossover(dziecko1, dziecko2, rodzic2); 
		}
		else {
			dziecko1 = new CGAIndividual(rodzic1);
			dziecko2 = new CGAIndividual(rodzic2);
		}


		dziecko1->vMutation((int) (d_mutProbability * 100.0));
		dziecko1->vCalculateFitness(*pc_Max3SatProblem);

		//dziecko1 = mutate(dziecko1);

		dziecko2->vMutation((int) (d_mutProbability * 100.0));
		dziecko2->vCalculateFitness(*pc_Max3SatProblem);

		//dziecko2 = mutate(dziecko2);

		(*newVPop).push_back(dziecko1);
		(*newVPop).push_back(dziecko2);
	}

	rodzic1 = NULL;
	rodzic2 = NULL;
	dziecko1 = NULL;
	dziecko2 = NULL;

	for (int i = 0; i < (int) (*vPopulation).size(); i++) {
		if ((*vPopulation).at(i) != NULL) {
			delete (*vPopulation).at(i);
		}
	}
	
	(*vPopulation).clear();
	vector<CGAIndividual*>* temp = vPopulation;

	vPopulation = newVPop;
	newVPop = temp;
	vSort();

	temp = NULL;
}

void CGAOptimizer::vSetPop(int iSize){
	i_popSize = iSize;
	if (vPopulation != NULL) delete vPopulation;
	vPopulation = new vector<CGAIndividual*>;
	(*vPopulation).reserve(i_popSize + 1);
	if (newVPop != NULL) delete newVPop;
	newVPop = new vector<CGAIndividual*>;
	(*newVPop).reserve(i_popSize + 1);
	cout << "vSetPop() - set amount of population." << endl << "i_popSize =" << i_popSize << endl;
}

void CGAOptimizer::vSetXProbability(double dXProb){
	d_xProbability = dXProb;
	cout << "vSetXProbability() - set Crossover probability." << endl << "d_xProbability =" << d_xProbability << endl;
}

void CGAOptimizer::vSetMutProbability(double dMutProb){
	d_mutProbability = dMutProb;
	cout << "vSetMutProbability() - set Mutation probability." << endl << "d_mutProbability =" << d_mutProbability << endl;
}

void CGAOptimizer::vSort() {
	sort((*vPopulation).begin(), (*vPopulation).end(), [](CGAIndividual l,CGAIndividual r) { return l.dFitness() > r.dFitness(); });
}

void CGAOptimizer::vShowSolutions(){
	for (int i = 0; i < (int) (*vPopulation).size(); i++) {
		cout << i << "\t";
		(*vPopulation).at(i)->vShow();
	}
}

CGAIndividual* CGAOptimizer::pc_ChooseParent(){

	int iRandPosition = rand() % (int)((*vPopulation).size() * SELECTION_POPULATION);
	CGAIndividual* pcVolunteer1 = (*vPopulation).at(iRandPosition);
	iRandPosition = rand() % (int)((*vPopulation).size() * SELECTION_POPULATION);
	CGAIndividual* pcVolunteer2 = (*vPopulation).at(iRandPosition);
	
	if (pcVolunteer1->dFitness() >= pcVolunteer2->dFitness()) {
		return pcVolunteer1;
	}
	else {
		return pcVolunteer2;
	}
}

CGAIndividual* CGAOptimizer::mutate(CGAIndividual* child) {
	CGAIndividual* temp = new CGAIndividual(child);
	temp->vMutation((int)(d_mutProbability * 100.0));
	temp->vCalculateFitness(*pc_Max3SatProblem);
	temp = optimize(temp, 1);
	temp->vCalculateFitness(*pc_Max3SatProblem);

	if (child->dFitness() < temp->dFitness()) {
		delete child;
		child = temp;
	}
	else {
		delete temp;
	}
	return child;

}

CGAIndividual* CGAOptimizer::optimize(CGAIndividual* toOptimize, int step) {
	CGAIndividual* bestOne = toOptimize;
	CGAIndividual temp(toOptimize);

	for (int i = 0; i < (int)toOptimize->vGetGenotype()->size(); i = i + step) {
		temp.vGetGenotype()->at(i) = !temp.vGetGenotype()->at(i);
		temp.vCalculateFitness(*pc_Max3SatProblem);
		if (bestOne->dFitness() > temp.dFitness()) {
			temp.vGetGenotype()->at(i) = !temp.vGetGenotype()->at(i);
		}
		else {
			bestOne->vGetGenotype()->at(i) = !bestOne->vGetGenotype()->at(i);
			bestOne->vCalculateFitness(*pc_Max3SatProblem);
		}
	}
	return bestOne;
}