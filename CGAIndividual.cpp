#include "CGAIndividual.h"
#include <time.h>
CGAIndividual::CGAIndividual(){ //stworzenie osobnika domyslnie nie losowo! -> przenies do innej funkcji
	d_currentFitness = 0.0;
	vec_genotype.reserve(1000);

}

void CGAIndividual::vInitialize(CMax3SatProblem& cProblem) {
	d_currentFitness = 0.0;
	for (int i = 0; i <= cProblem.iGetNumberOfVar(); i++) {
		vec_genotype.push_back(rand() % 2);
	}
	vCalculateFitness(cProblem);
}

void CGAIndividual::pcCrossover(CGAIndividual* pcChild1, CGAIndividual* pcChild2 ,CGAIndividual* cOther)
{
	int iFromWhichParent;
	for (int i = 0; i < this->vec_genotype.size(); i++) {
		iFromWhichParent = rand() % 2;
		if (iFromWhichParent == 0) {
			pcChild1->vec_genotype.push_back(this->vec_genotype.at(i));
			pcChild2->vec_genotype.push_back(cOther->vec_genotype.at(i));
		}
		else {
			pcChild1->vec_genotype.push_back(cOther->vec_genotype.at(i));
			pcChild2->vec_genotype.push_back(this->vec_genotype.at(i));
		}
	}
}

double CGAIndividual::dFitness()
{
	return d_currentFitness;
}

void CGAIndividual::vMutation()
{
	//dla kazdego genu losyjemy czy odwarcamy na przeciwny
	int iDoMutate;
	for (int i = 0; i < vec_genotype.size(); i++) {
		iDoMutate = rand() % 100;
		if (iDoMutate < 100) {
			this->vec_genotype.at(i) = !vec_genotype.at(i);
		}
	}
}

void CGAIndividual::vShow()
{
	std::cout << "\tR:= ";
	for (int i = 0; i < vec_genotype.size(); i++) {
		std::cout << vec_genotype.at(i);
	}
	std::cout << std::endl;
	std::cout << "\tdFitness:= " << d_currentFitness<<std::endl;
}

void CGAIndividual::vCalculateFitness(CMax3SatProblem& cProblem)
{
	d_currentFitness = cProblem.dCompute(vec_genotype);
}


