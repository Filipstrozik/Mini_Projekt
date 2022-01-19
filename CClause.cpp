#include "CClause.h"
#include <vector>

CClause::CClause() {
    b_FirstFlag = false;
    b_SecondFlag = false;
    b_ThirdFlag = false;
    i_first = 0;
    i_second = 0;
    i_third = 0;
}

CClause::CClause(int iFirst, int iSecond, int iThird) {
    b_FirstFlag = bSetFlag(iFirst);
    b_SecondFlag = bSetFlag(iSecond);
    b_ThirdFlag = bSetFlag(iThird);
    i_first = abs(iFirst);
    i_second = abs(iSecond);
    i_third = abs(iThird);
}

CClause::CClause(bool bFirstFlag, int iFirst, bool bSecondFlag, int iSecond, bool bThirdFlag, int iThird) {
    b_FirstFlag = bFirstFlag;
    b_SecondFlag = bSecondFlag;
    b_ThirdFlag = bThirdFlag;
    i_first = abs(iFirst);
    i_second = abs(iSecond);
    i_third = abs(iThird);
    //std::cout << "Stworzono Clause: (" << b_FirstFlag << " " << i_first << ", " << b_SecondFlag << " " << i_second << ", " << b_ThirdFlag << " " << i_third << ")" << std::endl;
}

CClause::~CClause(){

}

bool CClause::bCompute(vector<bool>* vecSolution)
{
    return (zmien(bGetFirstFlag(),(*vecSolution).at(iGetFirst()))
        or zmien(bGetSecondFlag(),(*vecSolution).at(iGetSecond()))
        or zmien(bGetThirdFlag(),(*vecSolution).at(iGetThird())));
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