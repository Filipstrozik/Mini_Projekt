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
Krzy�owanie(Crossover) = dziecko wypadkow� genotypu rodzic�w:
	np: 1sza liczba od pierwszego rodzica , 2ga liczba od drugiego rodzica


Mutacja = losowa zmiana (drobna) genotypu:
	modyfikacja gen�w o los. wartosc z przedzia�u [0.15; 0.15]



Populacja = zbi�r osobnik�w:
	Populacja => Selekcja (jak? = inna metoda) => na podstawie Selekcji robimy pary rodzic�w.
	maj�c pary rodzic�w => krzy�owanie z prawdop.:
		jezeli x > p to po prostu kopia
		jezeli x <= p  to krzyzujemy: => wymieniamy geny:
			losujemy pkt krzyzoawania, rozcinamy dwa osobniki na dwie czesci
			��czymy czesci na krzyz genotypy pomiedzy dzieci.
	Tworz now� populacje
	Mutacja:
		dla ka�dego osobnika w nowej populacji sprawdzamy prawdopodobienstwo mutacji
		jezeli tak to wartosc danego genu wymieniamy na inn� losowo wybrana (?) => flipFlag?

	Selekcja:
		


		





*/