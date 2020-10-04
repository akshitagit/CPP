#include <bits/stdc++.h> 
using namespace std; 
  
/* function to check whether two strings are anagram of  
each other */
bool areAnagram(string str1, string str2) 
{ 
     
    int n1 = str1.length(); //length of first string
    int n2 = str2.length(); ////length of second string
  
    // If length of both strings is not same, then they cannot be anagram 
    if (n1 != n2) 
        return false; 
  
    // Sort both the strings using sort()
    sort(str1.begin(), str1.end()); // Sorting first strting
    sort(str2.begin(), str2.end()); // Sorting second string
  
    // Compare sorted strings 
    for (int i = 0; i < n1; i++) 
        if (str1[i] != str2[i]) 
            return false; 
  
    return true; 
}