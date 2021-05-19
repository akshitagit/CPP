/* Reference this if your having trouble understanding the code in longAritmeticProgSub.cpp 
found in the dynamic_programming folder */
#include <iostream>
using namespace std;

// The function returns true if there exist three elements in arithmetic progression

bool a3 (int set[], int n) {
    for (int j = 1; j<n-1;j++) {
        int i = j-1, k = j+1;
        while (i >=0 && k <= n-1) {
            if (set[i] + set[k] == 2*set[j] ) return true;
            (set[i] + set[k] < 2*set[j])? k++ : i--;
        }
    }
    return false;
}

int main() {
    int test[] = {5,10,15,20,25,30};
    int n = sizeof(test)/sizeof(test[0]);
    a3(test, n)? cout << "yes\n" : cout << "no\n";
}