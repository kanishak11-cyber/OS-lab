// wap to find sortest job first
#include<stdio.h>
#include<stdlib.h>

void main(){
    int process,  totalWaitingTime = 0, totalTurnAroundTime = 0;
    float averageWaitingTime, averageTurnAroundTime;
    printf("Enter the number of process: ");
    scanf("%d", &process);
    int burstTime[process], arrivalTime[process], completionTime[process], waitingTime[process], turnAroundTime[process];
    printf("Enter the arrival time and burst time of each process:\n");
    for(int i = 0; i < process; i++){
        printf("Process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }
    int time = 0;
    for(int i = 0; i < process; i++){
        if(arrivalTime[i] > time){
            time = arrivalTime[i];
        }
        time += burstTime[i];
        completionTime[i] = time;
        waitingTime[i] = completionTime[i] - arrivalTime[i] - burstTime[i];
        turnAroundTime[i] = completionTime[i] - arrivalTime[i];
    }
    for(int i = 0; i < process; i++){
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }
    averageWaitingTime = (float)totalWaitingTime / process;
    averageTurnAroundTime = (float)totalTurnAroundTime / process;
    printf("\nProcess\t\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurn Around Time\n");
    for(int i = 0; i < process; i++){
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], completionTime[i], waitingTime[i], turnAroundTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", averageWaitingTime);
}