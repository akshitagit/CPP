//shortest job first program and gant chart display//
#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
int p[4],bt[4],wt[4],tat[4],i,j;


cout<<"enter the process name and burst time for 4 process"<<endl;
for(i=0;i<4;i++)
{
cin>>p[i]>>bt[i];

}
for(i=0;i<4;i++){
for(int j=i+1;j<4;j++)
{if(bt[i]>bt[j]){
swap(bt[i],bt[j]);
swap(p[i],p[j]);}
}
}

 
for(i=0;i<4;i++)
{
if(i>0)

{
wt[i]=wt[i-1]+bt[i-1];

}
else
{wt[0]=0;
}
}
for(i=0;i<4;i++)
{
tat[i]=bt[i]+wt[i];
}

cout<<"P"<<"  "<<"B.T"<<"  "<<"W.T"<<"  "<<"TAT"<<endl;
for(i=0;i<4;i++)
{
cout<<p[i]<<"    "<<bt[i]<<"     "<<wt[i]<<"   "<<tat[i]<<endl;
}
cout<<"gant chart:"<<endl;
for(i=0;i<4;i++)
{cout<<"|"<<p[i];

for(j=0;j<bt[i];j++)
{
cout<<" ";
}
}
cout<<"|"<<endl;
for(i=0;i<4;i++)
{
cout<<bt[i];
for(j=0;j<bt[i];j++)
{
cout<<" ";
}
}
return 0;
}
