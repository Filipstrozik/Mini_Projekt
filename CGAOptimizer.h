#pragma once
//int SIZE_OF_POP = 50; // ilosc populacji ilosc osobnikow
//double CROSS_PROBABILTY = 0.5;
// MUTATION_PROBABILITY = 0.5;
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
#include <vector>

class CGAOptimizer
{
public:
	CGAOptimizer();
	~CGAOptimizer();
	void vInitialize(std::string sPath); 
	void vRunIteration();

	void vSort();
	void vTestFitness();

	void vShowSolutions();

	CMax3SatProblem* pc_GetOptimizer(); // czy to potrzebne???


private:
	int i_popSize;
	double d_xProbability;
	double d_mutProbability;

	std::vector<CGAIndividual*> vPopulation; // populacja
	CMax3SatProblem* pc_Max3SatProblem; // problem - klazule

	//CGAIndividual* pc_bestIndividual;
	CGAIndividual* pc_ChooseParent();
	//CGAIndividual* pc_Crossover(CGAIndividual* pcParent1, CGAIndividual* pcParent2); // do individual
	//CGAIndividual* pc_Mutate(CGAIndividual* pcChild); // do individual
};
