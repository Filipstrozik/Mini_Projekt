#pragma once
#include <iostream>
#include <vector>

class CClause
{
public:
	CClause();
	CClause( int iFirst, int iSecond, int iThird) {
		b_FirstFlag = bSetFlag(iFirst);
		b_SecondFlag = bSetFlag(iSecond);
		b_ThirdFlag = bSetFlag(iThird);
		i_first = abs(iFirst); 
		i_second = abs(iSecond);
		i_third = abs(iThird);
	
		//std::cout << "Stworzono Clause: (" << b_FirstFlag << " " << i_first << ", " << b_SecondFlag << " " << i_second << ", " << b_ThirdFlag << " " << i_third << ")" << std::endl;
	};

	CClause(bool bFirstFlag, int iFirst, bool bSecondFlag, int iSecond, bool bThirdFlag, int iThird) {
		b_FirstFlag = bFirstFlag;
		b_SecondFlag = bSecondFlag;
		b_ThirdFlag = bThirdFlag;
		i_first = abs(iFirst);
		i_second = abs(iSecond);
		i_third = abs(iThird);

		//std::cout << "Stworzono Clause: (" << b_FirstFlag << " " << i_first << ", " << b_SecondFlag << " " << i_second << ", " << b_ThirdFlag << " " << i_third << ")" << std::endl;
	};

	//getters
	int iGetFirst() { return i_first; };
	int iGetSecond() { return i_second; };
	int iGetThird() { return i_third; };
	bool bGetFirstFlag() { return b_FirstFlag; };
	bool bGetSecondFlag() { return b_SecondFlag; };
	bool bGetThirdFlag() { return b_ThirdFlag; };


	//setters
	void iSetFirst(int iNewFirst);
	void iSetSecond(int iNewSecond);
	void iSetThird(int iNewThird);
	//te wlagi to nie wiem czy potrzebne w ogole
	void iFlipFirstFlag(); 
	void iFlipSecondFlag();
	void iFlipThirdFlag();

	bool bCompute(std::vector<bool> vecSolution);
	bool bSetFlag(int iVar);
	bool zmien(bool flaga, bool wynik);
private:
	int i_first;
	int i_second;
	int i_third;
	bool b_FirstFlag;
	bool b_SecondFlag;
	bool b_ThirdFlag;
	

};

/* 
Osobnik = genotyp (determinuje cechy osobnika)
Selekcja = osobniki lepiej przystosowane:
	- wieksza szansa na przetrwanie
	- Wieksza szansa na potomstwo
Krzy¿owanie(Crossover) = dziecko wypadkow¹ genotypu rodziców:
	np: 1sza liczba od pierwszego rodzica , 2ga liczba od drugiego rodzica


Mutacja = losowa zmiana (drobna) genotypu:
	modyfikacja genów o los. wartosc z przedzia³u [0.15; 0.15]



Populacja = zbiór osobników:
	Populacja => Selekcja (jak? = inna metoda) => na podstawie Selekcji robimy pary rodziców.
	maj¹c pary rodziców => krzy¿owanie z prawdop.:
		jezeli x > p to po prostu kopia
		jezeli x <= p  to krzyzujemy: => wymieniamy geny:
			losujemy pkt krzyzoawania, rozcinamy dwa osobniki na dwie czesci
			³¹czymy czesci na krzyz genotypy pomiedzy dzieci.
	Tworz now¹ populacje
	Mutacja:
		dla ka¿dego osobnika w nowej populacji sprawdzamy prawdopodobienstwo mutacji
		jezeli tak to wartosc danego genu wymieniamy na inn¹ losowo wybrana (?) => flipFlag?

	Selekcja:
		


		





*/