#pragma once
//int SIZE_OF_POP = 50; // ilosc populacji ilosc osobnikow
//double CROSS_PROBABILTY = 0.5;
// MUTATION_PROBABILITY = 0.5;
#include "CGAIndividual.h"
#include "CMax3SatProblem.h"
#include <vector>

class CGAOptimizer
{
public:
	CGAOptimizer();
	void vInitialize(std::string sPath); /* pozwalaj¹c¹ na przygotowanie
optymalizatora do dzia³ania,(zainicjuj Max3SatProblem - wczytaj klazule , w tym na losow¹ inicjacjê wszystkich osobników
(rozwi¹zañ). Losowa inicjacja polega na tym, ¿e jeœli rozwi¹zanie sk³ada siê
np. ze 100 zmiennych to ich wartoœci okreœlamy losowo.*/
	void vRunIteration();/*pozwalaj¹c¹ na uruchomienie pojedynczej
iteracji optymalizatora, w której zostanie utworzona nowa populacja rozwi¹zañ
i nast¹pi to w nastêpuj¹cych krokach:*/

	void vTestFitness();

	CMax3SatProblem* pc_GetOptimizer(); // czy to potrzebne???


private:
	int i_popSize;
	double d_xProbability;
	double d_mutProbability;

	std::vector<CGAIndividual*> vPopulation; // populacja
	CMax3SatProblem* pc_Max3SatProblem; // problem - klazule

	//CGAIndividual* pc_bestIndividual;
	CGAIndividual* pc_ChooseParent();
	CGAIndividual* pc_Crossover(CGAIndividual* pcParent1, CGAIndividual* pcParent2); // do individual
	CGAIndividual* pc_Mutate(CGAIndividual* pcChild); // do individual
};
/*
	nowaPopulacja = empty
 while (nowaPopulacja.size < Populacja.size) do
 rodzic1 = wybierzRodzica(Populacja)
 rodzic2 = wybierzRodzica(Populacja)
 dziecko1, dziecko2 = krzy¿owanie(rodzic1, rodzic2);
 dziecko1 = mutuj(dziecko1)
 dziecko2 = mutuj(dziecko2)
 DodajOsobnika(nowaPopulacja, dziecko1, dziecko2);
 end while
Populacja = nowaPopulacja
*/
