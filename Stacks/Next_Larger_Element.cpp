/* Implementation of Next Larger Element */

#include <bits/stdc++.h>
using namespace std;

void nextlarger(long long int arr[],int n)
{   
    stack<long long> st;
    int i;
    long long int nxt[n];

    for(i=n-1;i>=0;i--)
    {   if(st.empty())
            nxt[i] = -1;
        else{
            long long t = st.top();
            while(t<=arr[i])
            {
                st.pop();
                if(!st.empty())
                    t= st.top();
                else
                    break;
            }
            if(!st.empty())
                nxt[i]= t;
            else
                nxt[i] = -1;
        }
        st.push(arr[i]);
    }

    for(i=0;i<n;i++)
        cout<<nxt[i]<<" ";
}

int main() {
	
    int i,n;
    cin>>n;
    long long int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    nextlarger(arr,n);
    cout<<endl;
	
	return 0;
}