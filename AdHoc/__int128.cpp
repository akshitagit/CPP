#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 100;
    __int128 Ans = n;

    vector<char> vec;
    vec.clear();
    while(Ans) vec.push_back(Ans % 10 | 48), Ans /= 10;
    reverse(vec.begin(),vec.end());
    for(char x : vec) printf("%c",x);
    printf("\n");
}
