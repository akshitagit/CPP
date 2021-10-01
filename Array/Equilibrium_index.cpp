#include<bits/stdc++.h>
using namespace std;

int geteqindex(int *arr, int n){
     int ls,rs;

     for(int i=0;i<n;i++){
        //calculating the left sum for an particular index
            ls=0;
            for(int j=0;j<i;j++){
                ls+=arr[j];
            }
        //calculating the right sum for an particular index
             rs=0;
             for(int j=i+1;j<n;j++){
                rs+=arr[j];
             }
        //if both ls and rs are equal then we have found the eq index
             if(ls==rs)
             return i;         
     }
     //if theres no eq index 
     return -1;
    
}


int main() {
    int arr[]={3,-4, 2, -1,-3, 2, 1};
    int n=7;
    cout<<geteqindex(arr,n);

// Equlibrium index is that index in an array for which sum of all elements on the left is
//equal to sum of all the elements on the right   
}
