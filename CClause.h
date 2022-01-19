#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CClause
{
public:
	CClause();
	CClause(int iFirst, int iSecond, int iThird, int iFourth);
	CClause(bool bFirstFlag, int iFirst, bool bSecondFlag, int iSecond, bool bThirdFlag, int iThird, bool bFourthFlag, int iFourth);
	~CClause();

	//getters
	int iGetFirst() { return i_first; };
	int iGetSecond() { return i_second; };
	int iGetThird() { return i_third; };
	int iGetFourth() { return i_fourth; }
	bool bGetFirstFlag() { return b_FirstFlag; };
	bool bGetSecondFlag() { return b_SecondFlag; };
	bool bGetThirdFlag() { return b_ThirdFlag; };
	bool bGetFourthFlag() { return b_FourthFlag; };


	//setters
	void iSetFirst(int iNewFirst) { i_first = iNewFirst; };
	void iSetSecond(int iNewSecond) { i_second = iNewSecond; };
	void iSetThird(int iNewThird) { i_third = iNewThird; };
	void vSetFirstFlag(bool bNewFlag) { b_FirstFlag = bNewFlag; };
	void vSetSecondFlag(bool bNewFlag) { b_SecondFlag = bNewFlag; };
	void vSetThirdFlag(bool bNewFlag) { b_ThirdFlag = bNewFlag; };

	//crucial functions
	bool bCompute(vector<bool>* vecSolution);
;
private:
	int i_first;
	int i_second;
	int i_third;
	int i_fourth;
	bool b_FirstFlag;
	bool b_SecondFlag;
	bool b_ThirdFlag;
	bool b_FourthFlag;

	bool bSetFlag(int iVar);
	bool zmien(bool flaga, bool wynik);
};