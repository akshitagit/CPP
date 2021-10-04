#include <iostream>

#include <math.h>

using namespace std;

// <https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80>

/*
 
    Approximate Pi value using Leibniz formula:

    1 - 1/3 + 1/5 - 1/7 + 1/9 - ... = pi/4
    
    The more operations done the closer it is to pi
*/

int main() {
    double pi=0;
    int n, k;

    // give a number of operations to approximate pi
    printf("How many steps: ");
    cin >> n;

    // Leibniz's formula using summation notation
    for(k=0; k <= n; k++){
        pi += (pow(-1, k))/(double)((2*k)+1);
    }
    
    printf("%.15lf\n", pi*4);

    return 0;
}

