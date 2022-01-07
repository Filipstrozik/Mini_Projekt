#include <iostream>
#include <string>
#include "CMax3SatProblem.h"
#include "CGAIndividual.h"
#include "CGAOptimizer.h"
using namespace std;


int main() {
    cout << "Test " << endl;
    CGAOptimizer Optymalizator;
    Optymalizator.vInitialize("test.txt");
    Optymalizator.vTestFitness();
    Optymalizator.vRunIteration();

    


    return 0;
}