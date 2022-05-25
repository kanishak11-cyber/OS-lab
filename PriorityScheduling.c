// WAP to implement the priority scheduling 

#include<stdio.h>
#include<stdlib.h>
void main(){
    int processId[n], arrivalTime[n], burstTime[n],priority[n],turnAroundTime[n],waitingTime[n], n;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of each process:\n");
    for(int i = 0; i < n; i++){
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &arrivalTime[i], &burstTime[i], &priority[i]);
    }
    int time = 0;
    for(int i = 0; i < n; i++){
        if(arrivalTime[i] > time){
            time = arrivalTime[i];
        }
        time += burstTime[i];
        completionTime[i] = time;
        waitingTime[i] = completionTime[i] - arrivalTime[i] - burstTime[i];
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
    }
    for(int i = 0; i < n; i++){
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
    averageWaitingTime = (float)totalWaitingTime / process;
    averageTurnAroundTime = (float)totalTurnAroundTime / process;
    printf("\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0; i < n; i++){
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], waitingTime[i], turnAroundTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turn Around Time: %.2f\n", averageTurnAroundTime);
    
}