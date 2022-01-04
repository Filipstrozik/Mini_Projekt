#pragma once
#include <vector>
#include "CMax3SatProblem.h"

class CGAIndividual
{
public:
	CGAIndividual();
	CGAIndividual* pcCrossover(CGAIndividual& cOther);
	double dFitness();
	void vMutation();
private:
	std::vector<bool> vec_genotype;
	//rep:
	// vec = [0111];
	// v1 = false v2 = true, v3 = true, v4 = true
	// dla klauzuli (-1,2,4) => (--1,2,4) obie sa spelnione
	// lecz dla (-1,-3,-2) to jest niespelniona
	// ale r1 sprawia ze (--1,-3,-2) i jest wiec sukces
	double d_currentFitness;
	void vCalculateFitness(CMax3SatProblem& cProblem);

};

//TODO:
//jak wczytywaæ te klauzule i iniciowaæ zmienne
//mutation, crossover 
//konstruktor kopuj¹cy -> kopiujesz wektor i essa.
