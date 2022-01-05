#pragma once
int SIZE_OF_POP = 50; // ilosc populacji ilosc osobnikow
double CROSS_PROBABILTY = 0.5;
double MUTATION_PROBABILITY = 0.5;
#include "CGAIndividual.h"
#include <vector>
class CGAOptimizer
{
public:
	CGAOptimizer();
	void vInitialize(); /* pozwalaj�c� na przygotowanie
optymalizatora do dzia�ania, w tym na losow� inicjacj� wszystkich osobnik�w
(rozwi�za�). Losowa inicjacja polega na tym, �e je�li rozwi�zanie sk�ada si�
np. ze 100 zmiennych to ich warto�ci okre�lamy losowo.*/
	void vRunIteration();/*pozwalaj�c� na uruchomienie pojedynczej
iteracji optymalizatora, w kt�rej zostanie utworzona nowa populacja rozwi�za�
i nast�pi to w nast�puj�cych krokach:*/

private:
	int i_popSize;
	double d_xProbability;
	double d_mutProbability;
	std::vector<CGAIndividual*> vPopulation; // populacja
	CGAIndividual* pc_bestIndividual;
	CGAIndividual* pc_ChooseParent();
	CGAIndividual** pc_Crossover(CGAIndividual* pcParent1, CGAIndividual* pcParent2); // do individual
	CGAIndividual* pc_Mutate(CGAIndividual* pcChild); // do individual
};
/*
	nowaPopulacja = empty
 while (nowaPopulacja.size < Populacja.size) do
 rodzic1 = wybierzRodzica(Populacja)
 rodzic2 = wybierzRodzica(Populacja)
 dziecko1, dziecko2 = krzy�owanie(rodzic1, rodzic2);
 dziecko1 = mutuj(dziecko1)
 dziecko2 = mutuj(dziecko2)
 DodajOsobnika(nowaPopulacja, dziecko1, dziecko2);
 end while
Populacja = nowaPopulacja
*/
