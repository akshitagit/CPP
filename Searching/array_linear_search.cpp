#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
     int a[1024];
     for(int i=0;i<n;i++){
         cin>>a[i];
     }
       int key;
       cin>>key;
       int flag=0;
       int tem=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==key)
            {
                flag=1;
                tem=i;
                break;
            }
        }
         if(flag==1)
         {
             cout<<tem;
         }    
         else{
             cout<<"-1";
         }
    return 0;
}
