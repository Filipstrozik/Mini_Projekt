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

    for (int i = 0; i < 50; i++) {
        Optymalizator.vRunIteration();
        cout << i << " ";
    }

    cout << endl;
    Optymalizator.vShowSolutions();
    
    return 0;
}