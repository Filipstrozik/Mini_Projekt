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
/* pozwalaj�c� na przygotowanie
optymalizatora do dzia�ania, w tym na losow� inicjacj� wszystkich osobnik�w
(rozwi�za�). Losowa inicjacja polega na tym, �e je�li rozwi�zanie sk�ada si�
np. ze 100 zmiennych to ich warto�ci okre�lamy losowo.*/