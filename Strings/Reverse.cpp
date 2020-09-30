#include<bits/stdc++.h>
using namespace std;
int main(){
   string s;
   cout<<"Enter the string to be printed in reverse : ";
   cin>>s;
   for(int i=s.length();i>=0;i--){
      cout<<s[i];
   }
   cout<<"\n";
}
