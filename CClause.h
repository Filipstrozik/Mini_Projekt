#pragma once
#include <iostream>
#include <vector>

class CClause
{
public:
	CClause();
	CClause( int iFirst, int iSecond, int iThird);
	CClause(bool bFirstFlag, int iFirst, bool bSecondFlag, int iSecond, bool bThirdFlag, int iThird);

	//getters
	int iGetFirst() { return i_first; };
	int iGetSecond() { return i_second; };
	int iGetThird() { return i_third; };
	bool bGetFirstFlag() { return b_FirstFlag; };
	bool bGetSecondFlag() { return b_SecondFlag; };
	bool bGetThirdFlag() { return b_ThirdFlag; };


	//setters
	void iSetFirst(int iNewFirst) { i_first = iNewFirst; };
	void iSetSecond(int iNewSecond) { i_second = iNewSecond; };
	void iSetThird(int iNewThird) { i_third = iNewThird; };
	void vSetFirstFlag(bool bNewFlag) { b_FirstFlag = bNewFlag; };
	void vSetSecondFlag(bool bNewFlag) { b_SecondFlag = bNewFlag; };
	void vSetThirdFlag(bool bNewFlag) { b_ThirdFlag = bNewFlag; };
	//crucial functions
	bool bCompute(std::vector<bool> vecSolution);
;
private:
	int i_first;
	int i_second;
	int i_third;
	bool b_FirstFlag;
	bool b_SecondFlag;
	bool b_ThirdFlag;

	bool bSetFlag(int iVar);
	bool zmien(bool flaga, bool wynik);
	

};