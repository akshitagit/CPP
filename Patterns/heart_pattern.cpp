#include<iostream>
using namespace std;
int main(){
    int i,j,a,b;
    //upper part
    for(j=0;j<3;j++)
    {
        for(i=1;i<=20;i++)
        {
            if(i>=4-j && i<=6+j ||i>=15-j &&i<=17+j)
            cout<<"*";
            else
            {
                cout<<" ";
            }
            
            
        }
        cout<<endl;
       
    }
     //lowerpart
    for(a=1;a<=11;a++)
    {
        for(b=1;b<=20;b++)
        {
        if(b>=a-1&&b<=21-a)
        cout<<"*";
        else
        {
            cout<<" ";
        }
        }
    cout<<endl;  
    }
        
}

