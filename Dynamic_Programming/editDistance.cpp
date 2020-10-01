#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std; 

int editDistance(string s , string t , unordered_map<string ,int>& state){
	int m = s.size(); 
	int n = t.size(); 
	if(m==0){
		return n;
	}
	if(n==0){
		return m;
	}

	string ans = to_string(m) +"|" + to_string(n); 
	if(state.find(ans) != state.end()){
		return state[ans];
	}

	int op1 = 1 + editDistance(s.substr(1),t,state) ; // Remove 
	int op2 = 1 + editDistance(s,t.substr(1),state) ; // insert 
	int op3 = 1 + editDistance(s.substr(1),t.substr(1),state); // replace 

	state[ans] = min(op1,min(op2,op3)); 
	return state[ans]; 
}

int editDistance(string s , string t)
{
    int m = s.size(); 
    int n =t.size();
    int ** output = new int*[m+1]; 
   for(int i=0 ;i<=m ; i++)
   {
       output[i] = new int[n+1];
   }
   ///  output[i][j] --> it denotes the  
   // for the first row that means that the length of s= 0; and t length can be anything so we will initialise the first row with 0 ;
   for(int i=0 ;i<=n ;i++){
       output[0][i] = i;
   }
   // for the first column that means that the length of t= 0; and s length can be anything so we will initialise the first column with 0 ;
   for(int i=0 ;i<=m ;i++){
    output[i][0] = i;
   }
   for(int i=1 ;i<=m ;i++)
   {
       for(int j=1;j<=n ;j++)
       {
           if(s[m-i]==t[n-j])
           output[i][j] = output[i-1][j-1]; 
           else 
           {
               output[i][j] = 1 + min(output[i][j-1],min(output[i-1][j],output[i-1][j-1])); 
           }
       }
   }
   return output[m][n];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s , t ;
    cin >> s >> t ;  
    int ans = editDistance(s,t); 
    cout << ans << endl;
    return 0;
}
