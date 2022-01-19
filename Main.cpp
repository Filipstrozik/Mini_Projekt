#include <iostream>
#include <string>
#include "CGAOptimizer.h"
using namespace std;


int main() {
    int iPop, iIterations;
    double dXProb, dMutProb;
    CGAOptimizer Optymalizator;
    cout << "wprowadz: Iteracje, Wielkosc Populacji, Prawd. Krzyzowania, Prawd. Mutacji:" << endl;
    cin >> iIterations >> iPop>> dXProb >> dMutProb;
    Optymalizator.vSetPop(iPop);
    Optymalizator.vSetXProbability(dXProb);
    Optymalizator.vSetMutProbability(dMutProb);
    Optymalizator.vInitialize("test2.txt");

    for (int i = 0; i < iIterations; i++) {
        cout << i << " ";
        Optymalizator.vRunIteration();
    }

    cout << endl;
    Optymalizator.vShowSolutions();
    
    return 0;
}