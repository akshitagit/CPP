/*
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :

Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15
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

#include <bits/stdc++.h>
using namespace std;


void printVector(vector <int> &temp){
    
    for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<" ";
    cout<<endl;
}
void helper(int input[],int n,vector<int> &temp){
    
    if(n==0){
        printVector(temp);
        return;
    }
    
    //First call to include the current element indicated by input[0]
    temp.push_back(input[0]);
    helper(input+1,n-1,temp);
    
    //Second call for not including the current element
    temp.pop_back();
    helper(input+1,n-1,temp);
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    vector<int>temp;
    
    helper(input,size,temp);
    
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
