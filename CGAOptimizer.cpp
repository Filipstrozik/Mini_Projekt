#include "CGAOptimizer.h"
using namespace std;

CGAOptimizer::CGAOptimizer() {
	i_popSize = SIZE_OF_POP; 
	d_xProbability = CROSS_PROBABILTY;
	d_mutProbability = MUTATION_PROBABILITY;
	vPopulation.reserve(i_popSize);
}

void CGAOptimizer::vInitialize() {

}
/* pozwalaj¹c¹ na przygotowanie
optymalizatora do dzia³ania, w tym na losow¹ inicjacjê wszystkich osobników
(rozwi¹zañ). Losowa inicjacja polega na tym, ¿e jeœli rozwi¹zanie sk³ada siê
np. ze 100 zmiennych to ich wartoœci okreœlamy losowo.*/