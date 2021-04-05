#include <iostream>
using namespace std;

int sec_largest(int arr[],int n){
        int f,s,i;
        f=s=0;
        for(int i=0;i<n;i++){
            if(arr[i]>f){
                s=f;
                f = arr[i];
            }    
        }
        
        cout<<"The second largest no is: "<<s;
}
int main(){
    int num;
    int arr[num];
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    sec_largest(arr,num);
}
