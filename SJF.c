// wap to find sortest job first
// Theory:
// The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. SJN, also known as Shortest Job Next (SJN), can be preemptive or non-preemptive.  
// Characteristics of SJF Scheduling:

// Shortest Job first has the advantage of having a minimum average waiting time among all scheduling algorithms.
// It is a Greedy Algorithm.
// It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of ageing.
// It is practically infeasible as Operating System may not know burst times and therefore may not sort them. While it is not possible to predict execution time, several methods can be used to estimate the execution time for a job, such as a weighted average of previous execution times. 
// SJF can be used in specialized environments where accurate estimates of running time are available.
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

// Advantages of SJF:

// SJF is better than the First come first serve(FCFS) algorithm as it reduces the average waiting time.
// SJF is generally used for long term scheduling
// It is suitable for the jobs running in batches, where run times are already known.
// SJF is probably optimal in terms of average turnaround time.
// Disadvantages of SJF: 

// SJF may cause very long turn-around times or starvation.
// In SJF job completion time must be known earlier, but sometimes it is hard to predict.
// Sometimes, it is complicated to predict the length of the upcoming CPU request.
// It leads to the starvation that does not reduce average turnaround time.
