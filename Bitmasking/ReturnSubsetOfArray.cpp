/*
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.

Input format :

Line 1 : Size of array

Line 2 : Array elements (separated by space)
Sample Input:

3
15 20 12

Sample Output:

[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 

*/

/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

#include <bits/stdc++.h>
using namespace std;
void getSubsets(int input[],int n,int start,int numele,vector<int>&temp,vector<vector<int> >&ans){
    if(numele==0){
        ans.push_back(temp);
        return;
    }
    
    for(int i=start;i<n;i++){
        temp.push_back(input[i]);
        
        getSubsets(input,n,i+1,numele-1,temp,ans);
        
        temp.pop_back();
    }
        
}
int subset(int input[], int n, int output[][20]) {
    // Write your code here
    vector <int> temp;
    vector <vector <int> > ans;
    
    for(int i=1;i<=n;i++){
        getSubsets(input,n,0,i,temp,ans);
    }
    
    ans.push_back({});

    for (int i=0;i<ans.size();i++){
        output[i][0]=ans[i].size();
        for(int j=1;j<=ans[i].size();j++){
            output[i][j]=ans[i][j-1];
        }
    }
    return ans.size();
    

}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}