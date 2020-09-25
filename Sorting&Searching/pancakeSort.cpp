#include <iostream>
using namespace std;

int maxArr(int arr[], int last) {
    
    int max = 0;

    for(int i = 1; i < last; ++i) {

        if(arr[max] < arr[i]) {

            max = i;
        }
    }
    return max;
}

void swapArr(int arr[], int index) {
    
    int index1 = 0;

    while(index1 < index) {
        
        int temp = arr[index1];
        arr[index1] = arr[index];
        arr[index] = temp;
        index1++;
        index--;
    }
}
void showArr(int arr[], int size) {

    for(int i = 0; i < size; ++i) {

        cout<<arr[i]<<" ";
    }
    cout<<"\n";
} 

void pancakeSort(int arr[], int size) {

    for(int i = size-1; i > 0 ; --i) {
        
    
        int index = maxArr(arr, i);
        
        if(i != index) {
            
            swapArr(arr, index);
            swapArr(arr, i);
        }
    }
}


int main() {

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; ++i) {

        cin>>arr[i];
    }
    
    cout<<"Unsorted array : ";
    showArr(arr, n);
    
    pancakeSort(arr, n);

    cout<<"Sorted Array : ";
    showArr(arr, n);
}
/*

Unsorted array : 54 85 52 25 98 75 25 11 68 
Sorted Array   : 11 25 25 52 54 68 75 85 98 

*/