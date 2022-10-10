#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the number of processes = ";
  cin>>n;
  int at[n],bt[n],pr[n];
  cout<<"Enter process id\n";
  for(int i=0;i<n;i++)
    cin>>pr[i];
  cout<<"Enter arrival time\n";
  for(int i=0;i<n;i++)
    cin>>at[i];
  cout<<"Enter burst time\n";
  for(int i=0;i<n;i++)
    cin>>bt[i];
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n-1;j++)
        {
          if(at[i]<at[j])
          {
            int t=at[i];
            at[i]=at[j];
            at[j]=t;

            int k=bt[i];
            bt[i]=bt[j];
            bt[j]=k;

            int l=pr[i];
            pr[i]=pr[j];
            pr[j]=l;
          }
        }
    }
  int ct[n],wt[n],tat[n];
  float s=0.00,a=0.00,avw=0.00,avt=0.00;
  ct[0]=0;
  for(int i=0;i<n;i++)
    ct[i+1]=ct[i]+bt[i];
  for(int i=0;i<n;i++)
    tat[i]=ct[i+1]-at[i];
  for(int i=0;i<n;i++)
    wt[i]=tat[i]-bt[i];
  cout<<"Process     Arrival time      Burst time      Turn Around time     Waiting time\n";
  for(int i=0;i<n;i++)
    {
      cout<<pr[i]<<"                "<<at[i]<<"               "<<bt[i]<<"               "<<tat[i]<<"               "<<wt[i]<<"\n";
      s=s+tat[i];
      a=a+wt[i];
    }
  avw=a/n;
  avt=s/n;
  cout<<"Avg waiting time = "<<avw<<"\n";
  cout<<"Avg turn around time = "<<avt<<"\n";
  return 0;
}
