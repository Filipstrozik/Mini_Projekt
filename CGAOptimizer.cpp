#include "CGAOptimizer.h"
using namespace std;

CGAOptimizer::CGAOptimizer() {
	i_popSize = 200; //TODO trzeba zmienic na jakies zdefiniowane
	d_xProbability = 0.40;
	d_mutProbability = 0.40;
	vPopulation.reserve(i_popSize);
	pc_Max3SatProblem = NULL;
	cout << "CGAOptimizer()" << endl << "i_popSize =" << i_popSize << endl << "d_xProbability ="<< d_xProbability << endl << "d_mutProbability ="<< d_mutProbability << endl;

}

CGAOptimizer::~CGAOptimizer()
{
	for (int i = 0; i < vPopulation.size(); i++) {
		delete vPopulation.at(i);
	}
}

void CGAOptimizer::vInitialize(std::string sPath) {
	pc_Max3SatProblem = new CMax3SatProblem();
	pc_Max3SatProblem->bLoad(sPath);
	srand((int)time(NULL));
	CGAIndividual* pc_Indiv;
	for (int i = 0; i < i_popSize; i++) {
		pc_Indiv = new CGAIndividual();
		pc_Indiv->vInitialize(*pc_Max3SatProblem); // hmmm? adres czy wskaznik?
		vPopulation.push_back(pc_Indiv);
	}
	// delete?
}

void CGAOptimizer::vRunIteration()
{
	vPopulation.at(0)->vShow();
	std::vector<CGAIndividual*> newVPop;
	newVPop.reserve(200);//czy tyle samo co populacja
	//wsadz 10 najlepszych z vPop
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
			rodzic1->pcCrossover(dziecko1, dziecko2, rodzic2); // ok dziala
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
	for (int i = 0; i < vPopulation.size(); i++) {
		delete vPopulation.at(i);
	}

	vPopulation = newVPop;
	vSort();
	
}



void CGAOptimizer::vSort() {
	sort(vPopulation.begin(), vPopulation.end(), [](CGAIndividual l,CGAIndividual r) { return l.dFitness() > r.dFitness(); });
}

void CGAOptimizer::vShowSolutions()
{
	//sort(vPopulation.begin(), vPopulation.end(), [](CGAIndividual l, CGAIndividual r) { return l.dFitness() > r.dFitness(); });
	for (int i = 0; i < vPopulation.size(); i++) {
		cout << i << "\t";
		vPopulation.at(i)->vShow();
	}
}

CMax3SatProblem* CGAOptimizer::pc_GetOptimizer()
{
	if (pc_Max3SatProblem != NULL) {
		return pc_Max3SatProblem;
	}
	else {
		return NULL;
	}
}

CGAIndividual* CGAOptimizer::pc_ChooseParent() // selekcja turniej
{
	int iRandPosition = rand() % (int)(vPopulation.size()/4); // bierzemy 20 najleoszych
	//cout << "wybieram rodzica1 o indeksie: " << iRandPosition << endl;
	CGAIndividual* pcVolunteer1 = vPopulation.at(iRandPosition);
	//pcVolunteer1->vShow();
	iRandPosition = rand() % (int)(vPopulation.size() / 4);
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

void CGAOptimizer::vTestFitness() { // dla kazdego rozwiazania wyznacz fitnes klauzl
	CGAIndividual* pc_Indiv;
	cout << "vTestFitness()" << endl;
	for (int i = 0; i < (int)vPopulation.size(); i++) {
		pc_Indiv = vPopulation.at(i);
		for (int j = 0; j < (int)pc_Indiv->vGetGenotype().size(); j++) {
			cout << pc_Indiv->vGetGenotype().at(j);
		}
		cout << endl << pc_Indiv->dFitness() << endl;
		//cout << pc_Max3SatProblem->dCompute(pc_Indiv->vGetGenotype()) << endl;
	}

}