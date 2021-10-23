#include<bits/stdc++.h> 
using namespace std; 
int n; bool flag = 0;

void getZarr(string str, int Z[]); 
  
void search(string text, string pattern) { 
    string concat = pattern + "$" + text; 
    int l = concat.length(); 
  
    int Z[l]; 
    getZarr(concat, Z); 
  
    for (int i = 0; i < l; ++i){ 
        if (Z[i] == pattern.length()) {
            if(n - (i - pattern.length() -1 ) == n) cout << "0\n";
            else cout << n - (i - pattern.length() -1 ) << endl; 
            flag = 1;
            break;
    	}
    } 
} 
  
void getZarr(string str, int Z[]) {
    int n = str.length(); 
    int L, R, k; 
    L = R = 0; 
    for (int i = 1; i < n; ++i) { 
        if (i > R) { 
            L = R = i; 
            while (R<n && str[R-L] == str[R]) R++; 
            Z[i] = R-L; 
            R--; 
        } 
        else{ 
            k = i-L; 
            if (Z[k] < R-i+1) Z[i] = Z[k]; 
            else{ 
                L = i; 
                while (R<n && str[R-L] == str[R]) R++; 
                Z[i] = R-L; 
                R--; 
            } 
        } 
    } 
} 

int main() {
    cin >> n;
    string text; cin >> text;  text = text + text;
    string pattern;  cin >> pattern;
    search(text, pattern); 
    if(flag == 0) cout << "-1\n";
    return 0; 
} 
