/* In this problem we don't have to create a tree.
    We can directly sum the input values that has to be inserted in the node*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int sum=0;
    long long int n,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        sum+=num;
    }
    cout<<sum<<endl;
}
