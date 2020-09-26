#include<bits/stdc++.h>
using namespace std;

//update values of p,q,r,n before testing code
int A=p, B=q, C=r;
int D=n;

int main()
{
    int ia=0,ib=0,ic=0;
    
    vector<int> ans(D+1,1);
    
    int nexta = A;
    int nextb = B;
    int nextc = C;
    int cur;
    
    for(int i=0;i<D;i++)
    {
        cur = min(nexta,min(nextb,nextc));
        ans[i+1] = cur;
        if(cur==nexta)
        {
            ia++;
            nexta = ans[ia]*A;
        }
        if(cur==nextb)
        {
            ib++;
            nextb = ans[ib]*B;
        }
        if(cur==nextc)
        {
            ic++;
            nextc = ans[ic]*C;
        }
    }
    //removing 1 from start of answer array
    ans.erase(ans.begin());
    
    //printing the answer series
    for(int i:ans)
        cout<<i<<" ";
}
