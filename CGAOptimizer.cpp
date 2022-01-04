#include "CGAOptimizer.h"
using namespace std;

CGAOptimizer::CGAOptimizer() {
	i_popSize = SIZE_OF_POP;
	d_xProbability = CROSS_PROBABILTY;
	d_mutProbability = MUTATION_PROBABILITY;
}