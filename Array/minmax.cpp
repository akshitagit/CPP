#include <iostream>

using namespace std;

int main(){
    int A[] = {10,24,52,15,8,25,47,105,16,49};

    int len = sizeof(A)/sizeof(int);

    int min= INT32_MAX;
    int max= INT32_MIN;

    for(int i=0;i<10;i++){
        if(A[i]<min){
            min = A[i];
        }
        if(A[i] > max){
            max = A[i];
        }
    }

    cout << "Minimum is : " << min << endl;
    cout << "Maximum is : " << max << endl;
}