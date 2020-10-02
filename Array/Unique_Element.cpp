#include <iostream>
#include<algorithm>
using namespace std;

int main()
{
    int T,i;
    cin>>T;
    while(T--){
    int n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
     int count=0;
     for(i=0;i<n;i++){
        if(a[i+1]==a[i])
            count+=0;
       else
            count+=1;
     }
    cout <<count<< endl;
    }
    return 0;
}
