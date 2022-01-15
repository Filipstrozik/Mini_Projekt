#include <iostream>
#include <string>
#include "CGAOptimizer.h"
using namespace std;


int main() {
    int iPop;
    double dXProb, dMutProb;
    CGAOptimizer Optymalizator;
    cin >> iPop >> dXProb >> dMutProb;
    Optymalizator.vSetPop(iPop);
    Optymalizator.vSetXProbability(dXProb);
    Optymalizator.vSetMutProbability(dMutProb);
    Optymalizator.vInitialize("test.txt");

    for (int i = 0; i < 10; i++) {
        cout << i << " ";
        Optymalizator.vRunIteration();
    }

    cout << endl;
    Optymalizator.vShowSolutions();
    
    return 0;
}