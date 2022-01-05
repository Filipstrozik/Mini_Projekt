#include <iostream>
#include <string>
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
using namespace std;


int main() {
    cout << "Test " << endl;
    CMax3SatProblem p;
    p.bLoad("test.txt");

    CGAIndividual ind;


    return 0;
}