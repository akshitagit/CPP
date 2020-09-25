#include <bits/stdc++.h> 
using namespace std; 
  
/* function to check whether two strings are anagram of  
each other */
bool isAnagram(string s1, string s2) 
{ 
    int n1 = s1.size(); 
    int n2 = s2.size(); 
  
    if (n1 != n2) 
        return false; 
    sort(s1.begin(), s1.end()); 
    sort(s2.begin(), s2.end()); 
  
    for (int i = 0; i < n1; i++) 
        if (s1[i] != s2[i]) 
            return false; 
  
    return true; 
} 

int main(){
        String s1,s2;
        cin>>s1>>s2;
        if(isAnagram(s1,s2)){
                cout<<"Anagrams";
        }
        else{
                cout<<"Not Anagrams";
        }

}
