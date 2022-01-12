#include "CGAOptimizer.h"
using namespace std;

CGAOptimizer::CGAOptimizer() {
	i_popSize = SIZE_OF_POP;
	d_xProbability = CROSS_PROBABILTY;
	d_mutProbability = MUTATION_PROBABILITY;
	vPopulation.reserve(i_popSize+1);
	pc_Max3SatProblem = NULL;
	cout << "CGAOptimizer()" << endl << "i_popSize =" << i_popSize << endl << "d_xProbability ="<< d_xProbability << endl << "d_mutProbability ="<< d_mutProbability << endl;

}

CGAOptimizer::~CGAOptimizer()
{
	for (int i = 0; i < (int) vPopulation.size(); i++) {
		delete vPopulation.at(i);
	}
	vPopulation.clear();
	delete pc_Max3SatProblem;
}

void CGAOptimizer::vInitialize(std::string sPath) {
	pc_Max3SatProblem = new CMax3SatProblem();
	pc_Max3SatProblem->bLoad(sPath);
	srand((int)time(NULL));
	///CGAIndividual* pc_Indiv;
	for (int i = 0; i < i_popSize; i++) {
		//pc_Indiv = new CGAIndividual();
		//pc_Indiv->vInitialize(*pc_Max3SatProblem); // hmmm? adres czy wskaznik?
		//vPopulation.push_back(pc_Indiv);
		vPopulation.push_back(new CGAIndividual());
		vPopulation.at(i)->vInitialize(*pc_Max3SatProblem);
	}
}

void CGAOptimizer::vRunIteration()
{
	vPopulation.at(0)->vShow();
	std::vector<CGAIndividual*> newVPop;
	newVPop.reserve(i_popSize);
	//wsadz 10 najlepszych z vPop "elitizm"
	for (int i = 0; i < (int)(vPopulation.size()/40) ; i++) {
		CGAIndividual* temp = new CGAIndividual(vPopulation.at(i));
		newVPop.push_back(temp);
	}


	while (newVPop.size() < vPopulation.size()) {
		//cout << "SELEKCJA1: " << endl;
		CGAIndividual* rodzic1 = pc_ChooseParent(); // wybierz rodzica -> turniej -> selekcja
		//cout << "Wybrano1: " << endl;
		//rodzic1->vShow();
		//cout << "SELEKCJA2: " << endl;
		CGAIndividual* rodzic2 = pc_ChooseParent(); // wybierz rodzica -> turniej -> selekcja
		//cout << "Wybrano2: " << endl;
		//rodzic2->vShow();

		//cout << "KRZYZOWANIE: " << endl;

		CGAIndividual* dziecko1;
		CGAIndividual* dziecko2;

		int iDoCrossover = rand() % 100;
		if (iDoCrossover < (int) (d_xProbability*100.0)) {
			//cout << "NATEPUJE KRZYZOWANIE " << endl;
			dziecko1 = new CGAIndividual;
			dziecko2 = new CGAIndividual;
			rodzic1->pcCrossover(dziecko1, dziecko2, rodzic2); 
		}
		else {
			//cout << "NIE MA KRZYZOWANIE: " << endl;
			dziecko1 = new CGAIndividual(rodzic1);
			dziecko2 = new CGAIndividual(rodzic2);
		}
	
		//cout << "POROWANANIE DZIEKO RODZIC" << endl;
		//cout << "dziecko1" << endl;

		//dziecko1->vCalculateFitness(*pc_Max3SatProblem);
		//dziecko1->vShow();
		//cout << "rodzic1" << endl;
		//rodzic1->vShow();
		//dziecko2->vCalculateFitness(*pc_Max3SatProblem);
		//cout << "dziecko2" << endl;
		//dziecko2->vShow();
		//cout << "rodzic2" << endl;
		//rodzic2->vShow();

		//if (dziecko1->dFitness() < rodzic1->dFitness()) {
		//	dziecko1 =  new CGAIndividual(rodzic1);
		//}

		//if (dziecko2->dFitness() < rodzic2->dFitness()) {
		//	dziecko2 = new CGAIndividual(rodzic2);
		//}
		//cout << "PRZED MUTACJA:" << endl;
		//rodzic1 = new CGAIndividual(dziecko1);
		//rodzic2 = new CGAIndividual(dziecko2);

		//dziecko1->vShow();
		//dziecko2->vShow();
		//cout << "MUTACJA: " << endl;
		dziecko1->vMutation((int) (d_mutProbability * 100.0));
		dziecko1->vCalculateFitness(*pc_Max3SatProblem);
		//dziecko1->vShow();
		//cout << "MUTACJA2: " << endl;
		dziecko2->vMutation((int) (d_mutProbability * 100.0));
		dziecko2->vCalculateFitness(*pc_Max3SatProblem);
		//dziecko2->vShow();
		//cout << "rodzice przed mutacja:" << endl;
		//rodzic1->vShow();
		//rodzic2->vShow();

		//if (dziecko1->dFitness() < rodzic1->dFitness()) {
		//	dziecko1 = new CGAIndividual(rodzic1);
		//}

		//if (dziecko2->dFitness() < rodzic2->dFitness()) {
		//	dziecko2 = new CGAIndividual(rodzic2);
		//}
		//cout << "do populacji wybrano:" << endl;
		//dziecko1->vShow();
		//dziecko2->vShow();

		newVPop.push_back(dziecko1);
		newVPop.push_back(dziecko2);
	}
	//uswanie starej populacji nie ma wyciekow
	for (int i = 0; i < (int) vPopulation.size(); i++) {
		delete vPopulation.at(i);
	}
	//cout << vPopulation.size() << endl;
	vPopulation.clear();
	//cout << vPopulation.capacity() << endl;
	//cout << vPopulation.size() << endl;

	vPopulation = newVPop;
	vSort();
	
}

void CGAOptimizer::vSort() {
	sort(vPopulation.begin(), vPopulation.end(), [](CGAIndividual l,CGAIndividual r) { return l.dFitness() > r.dFitness(); });
}

void CGAOptimizer::vShowSolutions(){
	for (int i = 0; i < (int) vPopulation.size(); i++) {
		cout << i << "\t";
		vPopulation.at(i)->vShow();
	}
}

//CMax3SatProblem* CGAOptimizer::pc_GetOptimizer(){
	//if (pc_Max3SatProblem != NULL) {
	//	return pc_Max3SatProblem;
	//}
	//else {
		//return NULL;
	//}
//}

CGAIndividual* CGAOptimizer::pc_ChooseParent(){
	int iRandPosition = rand() % (int)(vPopulation.size() / 2);
	//cout << "wybieram rodzica1 o indeksie: " << iRandPosition << endl;
	CGAIndividual* pcVolunteer1 = vPopulation.at(iRandPosition);
	//pcVolunteer1->vShow();
	iRandPosition = rand() % (int)(vPopulation.size() / 2);
	//cout << "wybieram rodzica2 o indeksie: " << iRandPosition << endl;
	CGAIndividual* pcVolunteer2 = vPopulation.at(iRandPosition);
	//pcVolunteer2->vShow();
	
	if (pcVolunteer1->dFitness() >= pcVolunteer2->dFitness()) {
		return pcVolunteer1;
	}
	else {
		return pcVolunteer2;
	}
}
