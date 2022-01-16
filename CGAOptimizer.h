#pragma once
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
#include <vector>

#define SIZE_OF_POP 200
#define CROSS_PROBABILTY 0.40
#define MUTATION_PROBABILITY 0.40


class CGAOptimizer
{
public:

	CGAOptimizer();
	~CGAOptimizer();
	//crucial functions
	void vInitialize(std::string sPath); 
	void vRunIteration();
	//setters
	void vSetPop(int iSize);
	void vSetXProbability(double dXProb);
	void vSetMutProbability(double dMutProb);
	//void show functions
	void vSort();
	void vShowSolutions();

	//CMax3SatProblem* pc_GetOptimizer(); // czy to potrzebne???


private:
	int i_popSize;
	double d_xProbability;
	double d_mutProbability;

	std::vector<CGAIndividual*>* vPopulation; 
	std::vector<CGAIndividual*>* newVPop;

	CGAIndividual* rodzic1;
	CGAIndividual* rodzic2;

	CGAIndividual* dziecko1;
	CGAIndividual* dziecko2;

	CMax3SatProblem* pc_Max3SatProblem; 
	
	CGAIndividual* pc_ChooseParent();
};
