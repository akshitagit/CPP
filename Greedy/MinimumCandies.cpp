/*
Alice is a kindergarten teacher. She wants to give some candies
to the children in her class.  All the children sit in a line 
and each of them has a rating score according to his or her 
performance in the class.  Alice wants to give at least 1 candy 
to each child. If two children sit next to each other, then the 
one with the higher rating must get more candies. Alice wants to
minimize the total number of candies she must buy.

For example, assume her students' ratings are [4, 6, 4, 5, 6, 2]. 
She gives the students candy in the following minimal amounts
[1, 2, 1, 2, 3, 1]. 
She must buy a minimum of 10 candies.
*/


//Solution
// Use two pass technique,
// Initialize empty array of given size, i.e vector<int> v(n,1),
// first iterate over the given array from the begining,
// i.e from index 1 to n-1, 
// v[i]=v[i-1]+1,  if arr[i]>arr[i-1]
// second time iterate over the given array from the ending
// i.e from n-2 to 0
// v[i]=v[i+1]+1, if(arr[i] > arr[i+1] && v[i] <= v[i+1])
// at last, return the sum of all the element of the array v.

#include <bits/stdc++.h>

using namespace std;

long candies(int n, vector<int> arr) {
    vector<int> v(arr.size(),1);
    
    for(int i=1; i<arr.size(); i++) {
        if(arr[i] > arr[i-1])
            v[i] = v[i-1] + 1;
    }
    
    for(int i=arr.size()-2; i>=0; i--) {
        if(arr[i] > arr[i+1] && v[i] <= v[i+1])
            v[i] = v[i+1] + 1;
    }
    
    long sum=0;
    
    for(int i=0; i<v.size(); i++)
        sum+= v[i];
    
    return sum;
}

int main() {

    int n=6; //total number of ratings
    
    vector<int> rating{4, 6, 4, 5, 6, 2};

    cout << candies(n,rating);

    return 0;
}