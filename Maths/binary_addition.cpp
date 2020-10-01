#include<bits/stdc++.h>
using namespace std;

vector<char> add(char a,char b, char c)
{
    int sum = int(a-48) + int(b-48) + int(c-48);
    if(sum==3)
        return {'1','1'};
    if(sum==2)
        return {'1','0'};
    if(sum==1)
        return {'0','1'};
    if(sum==0)
        return {'0','0'};
}

string addBinary(string A, string B) {
    
    char carry = '0';
    int alen = A.length();
    int blen = B.length();
    string ans = "";
    vector<char> cur;
    alen--;blen--;
    while(alen>=0 && blen>=0)
    {
        cur = add(carry,A[alen],B[blen]);
        ans.push_back(cur[1]);
        carry = cur[0];
        alen--;blen--;
    }
    while(alen>=0)
    {
        cur = add(carry,A[alen],'0');
        ans.push_back(cur[1]);
        carry = cur[0];
        alen--;
    }
    while(blen>=0)
    {
        cur = add(carry,B[blen],'0');
        ans.push_back(cur[1]);
        carry = cur[0];
        blen--;
    }
    if(carry == '1')
        ans.push_back('1');
        
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string A,B;
    cin>>A>>B;
    
    cout<<addBinary(A,B);
}
