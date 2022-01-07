#pragma once
#include <vector>
#include <random>
#include "CMax3SatProblem.h"
#include <iostream>

class CGAIndividual
{
public:
	CGAIndividual();

	void vInitialize(CMax3SatProblem& cProblem);

	void pcCrossover(CGAIndividual* pcChild1, CGAIndividual* pcChild2 , CGAIndividual* cOther);
	double dFitness();
	void vMutation();

	std::vector<bool> vGetGenotype() { return vec_genotype; }; // czy wskznik????

	void vCalculateFitness(CMax3SatProblem& cProblem);

	void vShow();

private:
	std::vector<bool> vec_genotype;
	double d_currentFitness;
	

};

//TODO:
// 
//miej juz osobniki w populacji potem implementacja ponizej
//mutation, crossover 
//konstruktor kopuj¹cy -> kopiujesz wektor i essa.
//WORKS:
//jak wczytywaæ te klauzule i iniciowaæ zmienne -> prawie done ok