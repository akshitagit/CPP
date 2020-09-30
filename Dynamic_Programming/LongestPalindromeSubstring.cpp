#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        
        if(s.empty()){
            return s;  // return if string is empty
        }

        int n = s.length();   // length of given string

        bool match[n][n];  // 2d boolean array where index will be marked as true if subtring of index are palindromic.
        
        memset(match,false,sizeof(match));
        
        int length=1;     // length of longestpalindromic substring in s.
        
        int start=0;  //starting index.
        for(int i=0;i<n;i++){
            match[i][i] = true;   
            if(s[i]==s[i+1]){
                start=i; length=2; match[i][i+1]=true;
            }
        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){

                int j = i+len-1;  // end index for substring of length 'len'
                
                if( match[i+1][j-1] && s[i]==s[j] ){
                    match[i][j]=true;
                }
                if(match[i][j] && length<(j-i+1)){   
                    start=i; length = j-i+1;
                }
            }
        }
        
//         stdout match array for debugging
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 cout<<match[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        return s.substr(start,length);
    }
int main(){
    string s;
    cin>>s;
    cout<<longestPalindrome(s);
}