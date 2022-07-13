#include <iostream>
using namespace std;
 
// function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    // waiting time for first process will be 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  bt[i-1] + wt[i-1];
    }
}
 
// function to calculate turn around time
void findTurnAroundTime( int processes[], int n, int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime( int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);
 
    // display processes along with all details
    printf( "Processes   Burst time   Waiting time   Turn around time\n");
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf( "   %d          %d              %d           %d \n",i+1 ,bt[i] ,wt[i],tat[i] );
    }
 
    printf( "Average waiting time =  %.6f",(float)total_wt / (float)n);
    printf("\nAverage turn around time = %.6f", (float)total_tat / (float)n);
    printf("\n");
}
 
// main function
int main()
{
    // process ids
    int processes[] = { 1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];
 
    // burst time of all processes
    int  burst_time[] = {21, 3, 6, 2};
 
    findAverageTime(processes, n,  burst_time);
    
    return 0;
}
