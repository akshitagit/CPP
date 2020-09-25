#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter value of N => ";
    cin>>n;
    cout<<endl;


    for(int i=0;i<n;i++){

        for(int j=0;j<i;j++)
            cout<<"  ";

        for(int j=n-i;j>=1;j--)
            cout<<j<<" ";

        cout<<"0 ";

        for(int j=1;j<=n-i;j++)
            cout<<j<<" ";

        cout<<endl;
    }

    for(int i=0;i<n;i++)
        cout<<"  ";
    cout<<"0"<<endl;

    for(int i=0;i<n;i++){

        for(int j=0;j<(n-1)-i;j++)
            cout<<"  ";

        for(int j=i+1;j>=1;j--)
            cout<<j<<" ";

        cout<<"0 ";

        for(int j=1;j<=i+1;j++)
            cout<<j<<" ";

        cout<<endl;
    }
}