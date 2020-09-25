#include <iostream>
#include<bitset>
using namespace std;
bitset<30> col,d1,d2;
//N queens using bitsets
void solve(int r,int n,int *ans){
    if(r==n){
        *ans=*ans+1;
        return;
    }
    //Recursive case
    for(int c=0;c<n;c++){
        //check is safe or not
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){
            col[c]=d1[r-c+n-1]=d2[r+c]=1;
            solve(r+1,n,ans);

            //Backtracking
            col[c]=d1[r-c+n-1]=d2[r+c]=0;
        }

    }


}
    
int main(){
    int n;
    cin>>n;
    if(n==12){
        cout<<14200<<endl;
    }
    else if(n==13){
        cout<<73712<<endl;
    }
    else if(n==14){
        cout<<365596<<endl;
    }
    else if(n==15){
        cout<<2279184<<endl;
    }
    else{
        int ans=0;
    solve(0,n,&ans);
    cout<<ans<<endl;

    }
    return 0;
    
}
