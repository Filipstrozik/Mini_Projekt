#include "CClause.h"
#include <vector>

CClause::CClause() {
    b_FirstFlag = false;
    b_SecondFlag = false;
    b_ThirdFlag = false;
    b_FourthFlag = false;
    i_first = 0;
    i_second = 0;
    i_third = 0;
    i_fourth = 0;
}

CClause::CClause(int iFirst, int iSecond, int iThird, int iFourth) {
    b_FirstFlag = bSetFlag(iFirst);
    b_SecondFlag = bSetFlag(iSecond);
    b_ThirdFlag = bSetFlag(iThird);
    b_FourthFlag = bSetFlag(iFourth);
    i_first = abs(iFirst);
    i_second = abs(iSecond);
    i_third = abs(iThird);
    i_fourth = abs(iFourth);
}

CClause::CClause(bool bFirstFlag, int iFirst, bool bSecondFlag, int iSecond, bool bThirdFlag, int iThird, bool bFourthFlag, int iFourth) {
    b_FirstFlag = bFirstFlag;
    b_SecondFlag = bSecondFlag;
    b_ThirdFlag = bThirdFlag;
    b_FourthFlag = bFourthFlag;
    i_first = abs(iFirst);
    i_second = abs(iSecond);
    i_third = abs(iThird);
    i_fourth = abs(iFourth);
    std::cout << "Stworzono Clause: (" << b_FirstFlag << " " << i_first << ", " << b_SecondFlag << " " << i_second << ", " << b_ThirdFlag << " " << i_third << ", " << b_FourthFlag << " " << i_fourth << ")" << std::endl;
}

CClause::~CClause(){

}

bool CClause::bCompute(vector<bool>* vecSolution)
{
    return (zmien(bGetFirstFlag(),(*vecSolution).at(iGetFirst()))
        or zmien(bGetSecondFlag(),(*vecSolution).at(iGetSecond()))
        or zmien(bGetThirdFlag(),(*vecSolution).at(iGetThird()))
        or zmien(bGetFourthFlag(), (*vecSolution).at(iGetFourth()))
        );
}


bool CClause::zmien(bool flaga, bool wynik) {
    if (flaga) {
        return !wynik;
    }
    else {
        return wynik;
    }
}


bool CClause::bSetFlag(int iVar) {
    if (iVar >= 0) { 
        return false; 
    }
    else {
        return true;
    }
}