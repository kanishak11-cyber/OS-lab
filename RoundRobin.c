// WAP to implement Round Robin scheduling
#include<stdio.h>
void findWaitingTime(int processes[], int n,int bt[], int wt[], int quantum)
{
    int rem_bt[n];
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] = bt[i];
 
    int t = 0; // Current time
    while (1)
    {
        _Bool done = 1;
        for (int i = 0 ; i < n; i++)
        {   
            if (rem_bt[i] > 0)
            {
                done = 0; 
                if (rem_bt[i] > quantum)
                {
                    t += quantum;
                    rem_bt[i] -= quantum;
                }
                else
                {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1)
        break;
    }
}
void findTurnAroundTime(int processes[], int n,int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
void findavgTime(int processes[], int n, int bt[],int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Processes\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n ; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time = %f ", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %f ", (float)total_tat / (float)n);
}
int main()
{
    // process id's
    int processes[] = { 1, 2, 3, 4, 5 };
    // burst time of processes
    int burst_time[] = { 5, 3, 1, 2, 3 };
    // time quantum
    int quantum = 2;
    findavgTime(processes, 5, burst_time, quantum);
    return 0;

}