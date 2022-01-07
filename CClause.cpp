#include "CClause.h"
#include <vector>

bool CClause::bCompute(std::vector<bool> vecSolution)
{
    return (
        zmien(bGetFirstFlag(),vecSolution.at(iGetFirst()))
        or zmien(bGetSecondFlag(),vecSolution.at(iGetSecond()))
        or zmien(bGetThirdFlag(),vecSolution.at(iGetThird()))
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
    if (iVar >= 0) { // TODO bo nie wiem jak do koanca jakie przedizal dostajemy zmiennych tak jakby 
        return false; //nie ma zaprzeczenia = false
    }
    else {
        return true;
    }
}