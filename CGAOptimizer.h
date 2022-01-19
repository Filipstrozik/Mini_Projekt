#pragma once
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
#include <vector>
using namespace std;

#define SIZE_OF_POP 200
#define CROSS_PROBABILTY 0.80
#define MUTATION_PROBABILITY 0.40

#define SELECTION_POPULATION 0.5
#define ELITISM_PERCENTAGE 0.025

class CGAOptimizer
{
public:

	CGAOptimizer();
	~CGAOptimizer();
	//crucial functions
	void vInitialize(string sPath); 
	void vRunIteration();
	//setters
	void vSetPop(int iSize);
	void vSetXProbability(double dXProb);
	void vSetMutProbability(double dMutProb);
	//void show functions
	void vSort();
	void vShowSolutions();

private:
	int i_popSize;
	double d_xProbability;
	double d_mutProbability;

	vector<CGAIndividual*>* vPopulation; 
	vector<CGAIndividual*>* newVPop;

	CGAIndividual* rodzic1;
	CGAIndividual* rodzic2;

	CGAIndividual* dziecko1;
	CGAIndividual* dziecko2;

	CMax3SatProblem* pc_Max3SatProblem; 
	
	CGAIndividual* pc_ChooseParent();
};
