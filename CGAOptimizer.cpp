#include "CGAOptimizer.h"
using namespace std;

CGAOptimizer::CGAOptimizer() {
	cout << "CGAOptimizer()" << endl;
	i_popSize = 20; //TODO trzeba zmienic na jakies zdefiniowane
	d_xProbability = 0.5;
	d_mutProbability = 0.5;
	vPopulation.reserve(i_popSize);
	pc_Max3SatProblem = NULL;
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
	std::vector<CGAIndividual*> newVPop;
	newVPop.reserve(100);//czy tyle samo co populacja
	int counter = 0;
	while (newVPop.size() < vPopulation.size()) {
		cout << "SELEKCJA1: " << endl;
		CGAIndividual* rodzic1 = pc_ChooseParent(); // wybierz rodzica -> turniej -> selekcja
		cout << "Wybrano1: " << endl;
		rodzic1->vShow();
		cout << "SELEKCJA2: " << endl;
		CGAIndividual* rodzic2 = pc_ChooseParent(); // wybierz rodzica -> turniej -> selekcja
		cout << "Wybrano2: " << endl;
		rodzic2->vShow();
		cout << "KRZYZOWANIE: " << endl;
		CGAIndividual* dziecko1 = new CGAIndividual;
		CGAIndividual* dziecko2 = new CGAIndividual;
		rodzic1->pcCrossover(dziecko1, dziecko2, rodzic2); // ok dziala

		dziecko1->vCalculateFitness(*pc_Max3SatProblem);
		dziecko1->vShow();
		dziecko2->vCalculateFitness(*pc_Max3SatProblem);
		dziecko2->vShow();
		cout << "MUTACJA1: " << endl;
		dziecko1->vMutation();
		dziecko1->vShow();
		cout << "MUTACJA2: " << endl;
		dziecko2->vMutation();
		dziecko2->vShow();
		newVPop.push_back(dziecko1);
		newVPop.push_back(dziecko2);
		counter+=2;
	}
	cout << counter << endl;
	vPopulation = newVPop;
	
}

void CGAOptimizer::vTestFitness() { // dla kazdego rozwiazania wyznacz fitnes klauzl
	CGAIndividual* pc_Indiv;
	cout << "vTestFitness()" << endl;
	for (int i = 0; i < (int) vPopulation.size(); i++) {
		pc_Indiv = vPopulation.at(i);
		for (int j = 0; j < (int) pc_Indiv->vGetGenotype().size(); j++) {
			cout << pc_Indiv->vGetGenotype().at(j);
		}
		cout << endl << pc_Indiv->dFitness() << endl;
		//cout << pc_Max3SatProblem->dCompute(pc_Indiv->vGetGenotype()) << endl;
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
	int iRandPosition = rand() % vPopulation.size();
	CGAIndividual* pcVolunteer1 = vPopulation.at(iRandPosition);
	pcVolunteer1->vShow();
	iRandPosition = rand() % vPopulation.size();
	CGAIndividual* pcVolunteer2 = vPopulation.at(iRandPosition);
	pcVolunteer2->vShow();
	
	if (pcVolunteer1->dFitness() >= pcVolunteer2->dFitness()) {
		return pcVolunteer1;
	}
	else {
		return pcVolunteer2;
	}
}

/*
	wybierzRodzica – metoda wyboru osobnika z populacji. Jedn¹ z najprostszych
programistycznie (a wysoce skutecznych) jest metoda turniejowa. Wybieramy losowo z
równym prawdopodobieñstwem t osobników, gdzie t to rozmiar turnieju (zwykle t = 2).
Zwyciêzc¹ zostaje ten osobnik rozwi¹zanie, które jest najlepszej jakoœci (w tym przypadku
bêdzie to rozwi¹zanie, które spe³nia najwiêcej klauzul). Ka¿dy osobnik mo¿e braæ udzia³ w
dowolnej liczbie turniejów i mo¿e zostaæ rodzicem dowoln¹ liczbê razy
*/
