#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;
    for (int i = 1; i <= n/2; i++)
    {   cout<<"*";
        for (int k = 0; k < (n/2)-1; k++)
        {
            cout<<" ";
        }
        cout<<"*";
        if (i==1)
        {
            for (int k = 0; k<(n/2); k++)
            {
                cout<<"*";
            }
            
        }
        cout<<endl;
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"*";
    }
   cout<<endl;
   for (int i = 0; i < n/2; i++)
   {
       if (i!=(n/2)-1)
       {
           for (int k = 0; k < (n/2); k++)
           {
               cout<<" ";
           }
           cout<<"*";
       }
       else
       {
           for (int k = 0; k <(n/2)+1; k++)
           {
               cout<<"*";
           }
           
       }
       for (int k = 0; k < (n/2)-1; k++)
       {
           cout<<" ";
       }
       cout<<"*"<<endl;
   }
    return 0;
}