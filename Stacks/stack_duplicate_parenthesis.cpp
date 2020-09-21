#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main() {
  int t;string str;stack<char>s;int count;int flag;
  cin>>t;
  while(t--)
  {
    cin>>str;flag=0;
    for(int i=0;str[i]!='\0';i++)
    {
      if(str[i]!=')')
      s.push(str[i]);
      else{
        count=0;
        while(true){
        if(s.top()!='('){
         count++;
         s.pop();
        }
        if(s.top()=='('){
          s.pop();
          break;
        }
        }
        if(count==0){
        cout<<"Duplicate Found"<<endl;flag=1;}
      }
    }
    if(flag==0)
    cout<<"No Duplicates Found"<<endl;
  }
	return 0;
}
