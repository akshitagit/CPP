/*
Take as input S, a string. Write a function that removes all consecutive duplicates. Print the value returned.
Input Format

String
Constraints

A string of length between 1 to 1000
Output Format

String
Sample Input

aabccba

Sample Output

abcba

Explanation

For the given example, "aabccba", Consecutive Occurrence of a is 2, b is 1, and c is 2.

After removing all of the consecutive occurences, the Final ans will be : - "abcba".
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#define INF 10000999
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000009
#define PI 3.1415926535
using namespace std;

string removeduplicate(string word){
  string ans="";
  int l=word.length(); //length of input string
  for(int i=0;i<l-1;i++){
    if(word[i]!=word[i+1]){  //checking if current is duplicate or not
      ans=ans+word[i];
    }
  }
  if(word[l-1]!=word[l-2]){  // chcking wheather last item is duplicate or not
    ans=ans+word[l-1];
  }

  return ans;
}

int main(){
  string word,ans;
  cout<<"Enter a String :"<<endl;
  cin>>word;


  cout<<"Answer :"<<endl;
  ans=removeduplicate(word);
  cout<<ans<<endl;


}
