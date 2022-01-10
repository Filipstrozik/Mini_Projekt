#include <iostream>
#include <string>
#include "CGAOptimizer.h"
using namespace std;


int main() {
    CGAOptimizer Optymalizator;
    Optymalizator.vInitialize("test.txt");

    for (int i = 0; i < 10; i++) {
        Optymalizator.vRunIteration();
        cout << i << " ";
    }

    cout << endl;
    Optymalizator.vShowSolutions();
    
    return 0;
}