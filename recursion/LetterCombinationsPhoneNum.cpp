#include <bits/stdc++.h>
using namespace std;

unordered_map<char,string> umap = {{'2',"abc"},{'3',"def"},
{'4',"ghi"},{'5',"jkl"},
{'6',"mno"},{'7',"pqrs"},
{'8',"tuv"},{'9',"wxyz"}};

void getCombo(vector<string>& ans,string digits,int index,int max,string ds)
{
	if(index>=max)
	{
		ans.push_back(ds);
		return ;
	}
	
	int len = umap[digits[index]].size();
	
	for(int i=0;i<len;i++)
	{
		ds.push_back(umap[digits[index]][i]);
		getCombo(ans,digits,index+1,max,ds);
		ds.pop_back();
	}
	
	return ;
}
vector<string> letterCombinations(string digits) {
	
	vector<string> ans; 
	if(digits=="")
	{
		
		return ans;
	}
	    
	int max = digits.length(); 
	
	string ds;  
   	
   	getCombo(ans,digits,0,max,ds);
   	
   	
   	
   	return ans;
   	
   	
   
}

int main()
{
	vector<string> ans;
	ans = letterCombinations("22233");
	// cout<<ans.size()<<endl;    //can be max 11664 for "23456789"
	// for(auto s:ans)
	// 	cout<<s<<endl;
	
}
