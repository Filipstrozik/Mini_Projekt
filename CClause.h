#pragma once
class CClause
{
public:
	CClause();
	CClause(int iFirst, int iSecond, int iThird);

	//getters
	int iGetFirst();
	int iGetSecond();
	int iGetThird();
	bool bGetFirstFlag();
	bool bGetSecondFlag();
	bool bGetThirdFlag();


	//setters
	void iSetFirst(int iNewFirst);
	void iSetSecond(int iNewSecond);
	void iSetThird(int iNewThird);
	void iFlipFirstFlag();
	void iFlipSecondFlag();
	void iFlipThirdFlag();

private:
	int i_first;
	int i_second;
	int i_third;
	bool b_firstFlag;
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