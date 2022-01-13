#include "CGAIndividual.h"
#include <time.h>

const int DEFAULT_SIZE = 1000;

CGAIndividual::CGAIndividual(){
	d_currentFitness = 0.0;
	vec_genotype.reserve(DEFAULT_SIZE);
}

CGAIndividual::~CGAIndividual() { 
	
	

}

CGAIndividual::CGAIndividual(CGAIndividual* cOther)
{
	vec_genotype.reserve(DEFAULT_SIZE);
	for (int i = 0; i < (int) cOther->vec_genotype.size(); i++) {
		this->vec_genotype.push_back(cOther->vec_genotype.at(i));
	}
	d_currentFitness = cOther->d_currentFitness;
}

void CGAIndividual::vInitialize(CMax3SatProblem& cProblem) {
	for (int i = 0; i <= (int) cProblem.iGetNumberOfVar(); i++) {
		vec_genotype.push_back(rand() % 2);
	}
	vCalculateFitness(cProblem);
}

void CGAIndividual::pcCrossover(CGAIndividual* pcChild1, CGAIndividual* pcChild2 ,CGAIndividual* cOther)
{
	int iFromWhichParent;
	for (int i = 0; i < (int) this->vec_genotype.size(); i++) {
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

void CGAIndividual::vMutation(int dMutProb)
{
	int iDoMutate;
	for (int i = 0; i < (int) (vec_genotype.size()/15); i++) {
		iDoMutate = rand() % 100;
		if (iDoMutate < dMutProb) {
			//std::cout << i << " ";
			int index = rand() % vec_genotype.size();
			this->vec_genotype.at(index) = !vec_genotype.at(index);
		}
	}
}

void CGAIndividual::vShow()
{
	std::cout << "R:= ";
	for (int i = 0; i < (int) vec_genotype.size(); i++) {
		std::cout << vec_genotype.at(i);
	}
	//std::cout << std::endl;
	std::cout << "\t= " << d_currentFitness<<std::endl;
}

void CGAIndividual::vCalculateFitness(CMax3SatProblem& cProblem)
{
	d_currentFitness = cProblem.dCompute(vec_genotype);
}



