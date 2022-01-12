#pragma once

#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
#include <vector>

const int SIZE_OF_POP = 200; 
const double CROSS_PROBABILTY = 0.40;
const double MUTATION_PROBABILITY = 0.40;

class CGAOptimizer
{
public:
	CGAOptimizer();
	~CGAOptimizer();
	//crucial functions
	void vInitialize(std::string sPath); 
	void vRunIteration();
	//void show functions
	void vSort();
	void vShowSolutions();

	//CMax3SatProblem* pc_GetOptimizer(); // czy to potrzebne???


private:
	int i_popSize;
	double d_xProbability;
	double d_mutProbability;

	std::vector<CGAIndividual*> vPopulation; 
	CMax3SatProblem* pc_Max3SatProblem; 
	//metoda prywatna
	CGAIndividual* pc_ChooseParent();
};
