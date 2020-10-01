/*

 find element that appears once in an array where every other element appears twice

*/
#include<bits/stdc++.h>
using namespace std;

int findSingleFrequencyElement(vector<int> A) {
    int singleElement = 0;
    for(auto v: A) {
        singleElement ^= v;
    }
    return singleElement;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T--) {
        int i,N,val;
        vector<int> A;
        cin>>N;
        while(N--) {
            cin>>val;
            A.push_back(val);
        }
        cout<<""<<findSingleFrequencyElement(A)<<"\n";
        
    }
 }

 /* 
    Test Cases:
    Input :
    3   // nnumber of test cases
    5   // array size
    2 2 3 3 1  // array elements
    7
    3 4 2 5 4 3 2
    9
    3 6 4 5 4 3 6 5 9

    Output: 
    1
    5
    9
 */