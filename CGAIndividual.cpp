#include "CGAIndividual.h"
#include <time.h>



CGAIndividual::CGAIndividual(){
	d_currentFitness = 0.0;
	vec_genotype.reserve(DEFAULT_SIZE);
}

CGAIndividual::~CGAIndividual() { 
	

}

CGAIndividual::CGAIndividual(const CGAIndividual* cOther)
{
	vec_genotype.reserve(DEFAULT_SIZE);
	for (int i = 0; i < (int) cOther->vec_genotype.size(); i++) {
		vec_genotype.push_back(cOther->vec_genotype.at(i));
	}
	d_currentFitness = cOther->d_currentFitness;
}

void CGAIndividual::vInitializeGenotype(CMax3SatProblem& cProblem) {
	for (int i = 0; i <= (int) cProblem.iGetNumberOfVar(); i++) {
		vec_genotype.push_back(rand() % 2);
	}
	vCalculateFitness(cProblem);
}

void CGAIndividual::pcCrossover(CGAIndividual* pcChild1, CGAIndividual* pcChild2 ,CGAIndividual* cOther)
{
	int iFromWhichParent;
	for (int i = 0; i < (int) vec_genotype.size(); i++) {
		iFromWhichParent = rand() % 2;
		if (iFromWhichParent == 0) {
			pcChild1->vec_genotype.push_back(vec_genotype.at(i));
			pcChild2->vec_genotype.push_back(cOther->vec_genotype.at(i));
		}
		else {
			pcChild1->vec_genotype.push_back(cOther->vec_genotype.at(i));
			pcChild2->vec_genotype.push_back(vec_genotype.at(i));
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
	for (int i = 0; i < (int)(vec_genotype.size() * DEFAULT_NUMBERS_OF_MUTATION); i++) {
		iDoMutate = rand() % 100;
		if (iDoMutate < dMutProb) {
			int index = rand() % vec_genotype.size();
			vec_genotype.at(index) = !vec_genotype.at(index);
		}
	}
}

void CGAIndividual::vShow()
{
	cout << "R:= ";
	for (int i = 0; i < (int) vec_genotype.size(); i++) {
		cout << vec_genotype.at(i);
	}
	cout << "\t= " << d_currentFitness<<endl;
}

void CGAIndividual::vCalculateFitness(CMax3SatProblem& cProblem)
{
	d_currentFitness = cProblem.dCompute(vGetGenotype());
}



