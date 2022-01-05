#include "CGAIndividual.h"
#include <time.h>
CGAIndividual::CGAIndividual(){
	srand(time(NULL));
	d_currentFitness = 0.0;
	for (int i = 0; i < 10; i++) {
		vec_genotype.push_back(rand() % 2);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << vec_genotype.at(i);
	}
}


