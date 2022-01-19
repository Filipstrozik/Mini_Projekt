#pragma once
#include <vector>
#include <random>
#include "CMax3SatProblem.h"
#include <iostream>
using namespace std;

#define  DEFAULT_SIZE 1000
#define DEFAULT_NUMBERS_OF_MUTATION 0.07

class CGAIndividual
{
public:

	CGAIndividual();
	~CGAIndividual();
	CGAIndividual(const CGAIndividual* cOther);

	//curcial functions
	void vInitializeGenotype(CMax3SatProblem& cProblem);
	void pcCrossover(CGAIndividual* pcChild1, CGAIndividual* pcChild2 , CGAIndividual* cOther);
	void vMutation(int dMutProb);
	//getters
	double dFitness();
	//crucial funtions

	
	vector<bool>* vGetGenotype() { return &vec_genotype; };

	//setters
	void vCalculateFitness(CMax3SatProblem& cProblem);

	//void show
	void vShow();

private:
	vector<bool> vec_genotype; 
	double d_currentFitness;
};
