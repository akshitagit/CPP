#include<iostream>
using namespace std;
void DNFSort(int arr[],int n ){
int s = 0;
int mid = 0;
int e = n-1;
while(mid<=e){
    if(arr[mid] == 0){
        swap(arr[mid], arr[s]);
        s++;
        mid++;
    }
    else if(arr[mid] == 1){ 
        mid++;
    }
    else if(arr[mid] == 2){
        swap(arr[mid], arr[e]); 
        e--;
    }
}
return ;
}
int main(){
    int n;
    cin>>n;
    int arr[1000];
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    DNFSort(arr, n);
    for (int i = 0; i < n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}