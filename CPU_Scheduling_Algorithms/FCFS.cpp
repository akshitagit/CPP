#include <bits/stdc++.h>
#include<map>
using namespace std;

int main() 
{
  int n;
  cout<<"Enter no of Process\n";
  cin>>n;
  multimap<int,int>AB; //multimap to store data of AT and BT
  vector<int>AT ,BT, CT, TAT, WT;
  cout<<"AT BT\n";
  for(int i=0; i<n; i++)
  {
      int a,b;
      cin>>a>>b;//taking input of AT in a and BT in b
      AB.insert(pair<int, int>(a, b));
  }
  int co=0;
  for(auto an=AB.begin(); an!=AB.end(); an++)
  {
      co=max((an->first),co);// it will check for ideal condition CPU
      AT.push_back((an->first));// Adding AT
      BT.push_back((an->second));//Adding BT
      co=co+an->second;
      CT.push_back(co);//adding CT
      int m=co-an->first; //TAT=CT-AT
      TAT.push_back(m);//adding TAT
      int v=m-an->second; //WT= TAT-BT
      WT.push_back(v); // adding WT
  }
  float avgTAT=0, avgWT=0; 
  for(int i=0; i<n; i++)
  {
    avgTAT=avgTAT+TAT[i];//sum of TAT
    avgWT=avgWT+WT[i];//sum of WT
  }
  avgTAT/=n;//Average TAT
  avgWT/=n;// Average WT

  // Displaying values 
  cout<<"AT\tBT\tCT\tTAT\tWT\n";
  for(int i=0; i<n; i++)
  {
    cout<<AT[i]<<"\t"<<BT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<endl; 
  }
  cout<<"\nAverage TAT  "<<avgTAT;
  cout<<"\nAverage WT  "<<avgWT;
  return 0;
}
