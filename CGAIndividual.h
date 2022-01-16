#pragma once
#include <vector>
#include <random>
#include "CMax3SatProblem.h"
#include <iostream>

#define  DEFAULT_SIZE 1000

class CGAIndividual
{
public:

	CGAIndividual();
	~CGAIndividual();
	CGAIndividual(const CGAIndividual* cOther);

	//curcial functions
	void vInitialize(CMax3SatProblem& cProblem);
	void pcCrossover(CGAIndividual* pcChild1, CGAIndividual* pcChild2 , CGAIndividual* cOther);
	void vMutation(int dMutProb);

	//getters
	double dFitness();
	std::vector<bool> vGetGenotype() { return vec_genotype; };

	//setters
	void vCalculateFitness(CMax3SatProblem& cProblem);

	//void show
	void vShow();

private:
	std::vector<bool> vec_genotype; 
	double d_currentFitness;
};
