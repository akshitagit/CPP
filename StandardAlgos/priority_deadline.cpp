#include <stdio.h>
int numbers[1000] = {0};
struct Processes {
int processId[10];
int burstTime[10];
int priority[10];
int deadline[10];
}processes;
struct DeadlineQueue {
int processId[10];
int burstTime[10];
int priority[10];
int deadline[10];
}dlQ;
struct PriorityQueue {
int processId[10];
int burstTime[10];
int priority[10];
int deadline[10];
}pQ;
int main() {
int pid, bt, p, dl, nop, ctr, temp = 0;
printf("Enter number of processes: ");
scanf("%d", &nop);
for(ctr = 0; ctr < nop; ctr++)
{
printf("Enter process id: P");
scanf("%d", &pid);
printf("Enter burst time: ");
scanf("%d",&bt);
printf("Enter priority: ");
scanf("%d",&p);
printf("Enter deadline: ");
scanf("%d", &dl);
if(newProcess(pid))
{
if(deadlineFunctionValid(bt, dl))
{
//printf("Process saved\n");
temp++;
saveProcess(ctr, pid, bt, p, dl);
}
else
{
printf("Deadline function not aplicable on this process.\n");
}
}
else
{
printf("Process with process id P%d is already present inr the queue.\n", pid);
}
}
nop = temp;
showProcesses(nop);
updateDeadlineQueue(nop);
updatePriorityQueue(nop);
showDeadlineQueue(nop);
showPriorityQueue(nop);
scheduleProcesses(nop);
//printf("%s", pid);
}
int newProcess(int pid)
{
if(numbers[pid] == 0)
{
numbers[pid]++;
return 1;
}
else
return 0;
}
int deadlineFunctionValid(int bt, int dl)
{
static largestDeadline = 0;
static leastDeadline = 999;
static largestDeadlineBT = 0;
if(dl >= bt + largestDeadline)
{
largestDeadline = dl;
largestDeadlineBT = bt;
return 1;
}
else if(dl + bt <= leastDeadline)
{
leastDeadline = dl;
return 1;
}
else if(dl >= bt + leastDeadline && dl <= largestDeadline - largestDeadlineBT)
{
return 1;
}
else
return 0;
}
saveProcess(int ctr, int pid, int bt, int p, int dl)
{
processes.processId[ctr] = pid;
processes.burstTime[ctr] = bt;
processes.priority[ctr] = p;
processes.deadline[ctr] = dl;
dlQ.processId[ctr] = pid;
dlQ.burstTime[ctr] = bt;
dlQ.priority[ctr] = p;
dlQ.deadline[ctr] = dl;
pQ.processId[ctr] = pid;
pQ.burstTime[ctr] = bt;
pQ.priority[ctr] = p;
pQ.deadline[ctr] = dl;
}
void showProcesses(int nop)
{
int i = 0;
printf("PID \t Burst Time \t Priority \t Deadline\n");
for(; i < nop; i++)
{
printf("P%d\t\t%d\t\t%d\t\t%d\n", processes.processId[i], processes.burstTime[i],
processes.priority[i], processes.deadline[i]);
}
}
void showDeadlineQueue(int nop)
{
int i = 0;
printf("---------------Deadline Queue---------------\n");
printf("PID \t Burst Time \t Priority \t Deadline\n");
for(; i < nop; i++)
{
printf("P%d\t\t%d\t\t%d\t\t%d\n", dlQ.processId[i], dlQ.burstTime[i], dlQ.priority[i], dlQ.deadline[i]);
}
}
void showPriorityQueue(int nop)
{
int i = 0;
printf("---------------Priority Queue---------------\n");
printf("PID \t Burst Time \t Priority \t Deadline\n");
for(; i < nop; i++)
{
printf("P%d\t\t%d\t\t%d\t\t%d\n", pQ.processId[i], pQ.burstTime[i], pQ.priority[i], pQ.deadline[i]);
}
}
void updateDeadlineQueue(int nop)
{
int i, j, tempPid, tempBt, tempP, tempDl;
for(i = 0; i < nop; i++)
{
for(j = 0; j < nop - 1; j++)
{
if(dlQ.deadline[j] > dlQ.deadline[j + 1])
{
tempPid = dlQ.processId[j];
tempBt = dlQ.burstTime[j];
tempP = dlQ.priority[j];
tempDl = dlQ.deadline[j];
dlQ.processId[j] = dlQ.processId[j + 1];
dlQ.burstTime[j] = dlQ.burstTime[j + 1];
dlQ.priority[j] = dlQ.priority[j + 1];
dlQ.deadline[j] = dlQ.deadline[j + 1];
dlQ.processId[j + 1] = tempPid;
dlQ.burstTime[j + 1] = tempBt;
dlQ.priority[j + 1] = tempP;
dlQ.deadline[j + 1] = tempDl;
}
}
}
}
void updatePriorityQueue(int nop) {
int i, j, tempPid, tempBt, tempP, tempDl;
for(i = 0; i < nop; i++)
{
for(j = 0; j < nop
- 1; j++)
{
if(pQ.priority[j] > pQ.priority[j + 1])
{
tempPid = pQ.processId[j];
tempBt = pQ.burstTime[j];
tempP = pQ.priority[j];
tempDl = pQ.deadline[j];
pQ.processId[j] = pQ.processId[j + 1];
pQ.burstTime[j] = pQ.burstTime[j + 1];
pQ.priority[j] = pQ.priority[j + 1];
pQ.deadline[j] = pQ.deadline[j + 1];
pQ.processId[j + 1] = tempPid;
pQ.burstTime[j + 1] = tempBt;
pQ.priority[j + 1] = tempP;
pQ.deadline[j + 1] = tempDl;
}
}
}
}
void scheduleProcesses(int nop) {
int PQIndex = 0;
int DQIndex = 0;
int elapsedTime = 0;
int scheduledProcess =-1;
int i, j, k;
printf("\n Proceeses will be scheduled in the following order--->\n");
for(i = 0; i < nop; i++)
{
//printf("YYY");
if(pQ.processId[PQIndex] != -1 && dlQ.processId[DQIndex] != -1)
{
//printf("xxx");
if(pQ.processId[PQIndex] == dlQ.processId[DQIndex])
{
printf("P%d\t", pQ.processId[PQIndex]);
elapsedTime += pQ.burstTime[PQIndex];
pQ.processId[PQIndex] = -1;
PQIndex++;
for(j = PQIndex; j < nop; j++)
{
if(pQ.processId[j] == -1)
PQIndex++;
else
break;
}
dlQ.processId[DQIndex] = -1;
DQIndex++;
for(j = DQIndex; j < nop; j++)
{
if(dlQ.processId[j] == -1)
DQIndex++;
else
break;
}
}
else if(elapsedTime + pQ.burstTime[PQIndex] + dlQ.burstTime[DQIndex] <= dlQ.deadline[DQIndex])
{
printf("P%d\t", pQ.processId[PQIndex]);
elapsedTime += pQ.burstTime[PQIndex];
scheduledProcess = pQ.processId[PQIndex];
pQ.processId[PQIndex] = -1;
PQIndex++;
for(j = PQIndex; j < nop; j++)
{
if(pQ.processId[j] == -1)
PQIndex++;
else
break;
}
for(k = DQIndex; k < nop; k++)
{
if(dlQ.processId[k] == scheduledProcess)
{
dlQ.processId[k] = -1;
break;
}
}
}
else
{
printf("P%d\t", dlQ.processId[DQIndex]);
elapsedTime += dlQ.burstTime[DQIndex];
scheduledProcess = dlQ.processId[DQIndex];
dlQ.processId[DQIndex] = -1;
DQIndex++;
for(j = DQIndex; j < nop; j++)
{
if(dlQ.processId[j] == -1)
DQIndex++;
else
break;
}
for(k = PQIndex; k < nop; k++)
{
if(pQ.processId[k] == scheduledProcess)
{
pQ.processId[k] = -1;
break;
}
}}}}}