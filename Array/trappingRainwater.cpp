// Author - Nishit Bansal, Nishit278 @github 
// Solution using 2 pointer method  
// Time Complexity - O(n)

#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& h) {
        int n = h.size();
        int left =  0;
        int maxLeft = 0, maxRight = 0;
        int right = n-1;
        int ans = 0;
        
        while(left <= right){
            if(h[left] <= h[right]){
                if(maxLeft <= h[left]) maxLeft = h[left];
                else ans+=maxLeft-h[left];
                left++;
            } else {
                if(maxRight <= h[right]) maxRight = h[right];
                else ans+=maxRight - h[right];
                right--;
            }
        }
        return ans;
    }

// Driver's code 
int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v[i] = x;
    }
    
    cout << trap(v) << endl;
    return 0;
}