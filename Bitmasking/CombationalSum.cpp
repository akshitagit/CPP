/*
Given an array of integers A and an integer B. Find and return all unique combinations in A where the sum of elements is equal to B.
Elements of input array can be repeated any number of times.
One combination should be saved in increasing order. Order of different combinations doesn't matter.
Note : All numbers in input array are positive integers.
Input Format :

Line 1 : Integer n
Line 2 : n integers (separated by space)
Line 3 : Integer B (i.e. sum)

Output Format :

Combinations in different lines

Contraints :
1<= N <=1000
Sample Input 1 :

4
7 2 6 5
16

Sample Output 1 :

2 2 2 2 2 2 2 2 
2 2 2 2 2 6 
2 2 2 5 5 
2 2 5 7 
2 2 6 6 
2 7 7 
5 5 6

Sample Input 2 :

4
2 4 6 8
8

Sample Output 2 :

2 2 2 2 
2 2 4 
2 6 
4 4 
8 

*/

#include <bits/stdc++.h>
using namespace std;



void help(vector <int> &a,int pos,int B,int sum,vector<int> &temp,vector<vector <int> >&ans){
    
    if(sum>B)
        return;
    if(pos==a.size())
        return;
    if(sum==B){
        ans.push_back(temp);
        return;
    }
    temp.push_back(a[pos]);
    help(a,pos,B,sum+a[pos],temp,ans);
    
    temp.pop_back();
    help(a,pos+1,B,sum,temp,ans);
    
}
vector<vector<int> > combinationSum(vector<int>& ar, int sum){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    vector <int> input;
    vector <int> temp;
    vector<vector <int> > ans;
    
    set <int> s;
    for(int i=0;i<ar.size();i++)
        s.insert(ar[i]);
    
    set <int> :: iterator it;
    for(it=s.begin();it!=s.end();it++)
        input.push_back(*it);
    
    help(input,0,sum,0,temp,ans);
    
    return ans;

}

int main() {
    int n;
    cin >> n;
    int x;
	vector<int> ar;
    for(int i = 0; i < n; i++){
        cin >> x;
    	ar.push_back(x);
    }
    int sum;
    cin >> sum;
	vector<vector<int> > res = combinationSum(ar, sum);
	if (res.size() == 0) {
		cout << "Empty";
		return 0;
	}
	for (int i = 0; i < res.size(); i++) {
		if (res[i].size() > 0) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}
	}
}
