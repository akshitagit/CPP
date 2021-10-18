#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

/*
given team names and their preferred placements find one ranklist with the minimal possible badness

Approach : in order to minimize the badness we need to give the team a rank closest to their preferred rank 

This is O(NlogN) approach
this problem can also be solved using counting sort
we update the frequency of the required ranks by the team 

*/



int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int arr[10000]={0};
        string name;
        int n,rank;
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>name>>rank;
            cout<<"Name is : "<<name<<" Rank is : "<<rank<<endl;
            
            arr[rank]++;
        }

        //greedy appraoch : assign the team nearest rank available 

        int sum=0;
        int actualRank=1;

        for(int i=1;i<n;i++)
        {
            cout<<"Current element is : "<<arr[i]<<endl;
            while(arr[i])
            {
                sum+=abs(actualRank-i);
                cout<<"Increasing badness by : "<<actualRank-i<<endl;
                arr[i]--;
                actualRank++;
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}