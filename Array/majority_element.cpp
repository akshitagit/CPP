/*  
    Using Moore's Voting Approach
    T = O(n)
    S = O(1)
*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int majorityElement(vector<int>& A) {
    int candidate = A[0];   // assume first element as majority element
    int count = 1;

    int n = A.size();
    for(int i=1; i<n; i++)  {
        if(A[i]==candidate) {
            // if same element, increase count
            count++;
        }
        else    {
            // if not same, decrease count
            count--;
            if(count==0)    {
                // if count becomes 0, update majority element
                candidate = A[i];
                count = 1;
            }
        }
    }

    // we can't assume that majority element exists
    int count2 = 0;
    for(int i=0; i<n; i++)  {
        if(A[i]==candidate) {
            count2++;
        }
    }
    if(count2>n/2)
        return candidate;   // candidate exists in majority
    else
        return -1;
}

int main()  {
    vector<int> A = {2,2,1,2,1,3,7,2,2,2,3,2};
    int res = majorityElement(A);
    if(res==-1)
        cout<<"No majority element exists"<<endl;
    else
        cout<<"Majority element = "<<res<<endl;
    return 0;
}