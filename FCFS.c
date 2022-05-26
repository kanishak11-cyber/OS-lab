// Objective: Implement FCFS (First Come First Serve) CPU Scheduling.
// Theory:
// First Come, First Served (FCFS) also known as First In, First Out(FIFO) is the CPU scheduling algorithm in which the CPU is allocated to the processes in the order they are queued in the ready queue.
// FCFS follows non-preemptive scheduling which mean once the CPU is allocated to a process it does not leave the CPU until the process will not get terminated or may get halted due to some I/O interrupt.

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
    printf("Average Turn Around Time: %.2f\n", averageTurnAroundTime);

}
// Output

// #image.png

// Advantages:
// 1.	It is simple and easy to understand.

// Disadvantages:
// 1.	The process with less execution time suffer i.e. waiting time is often quite long.
// 2.	Favors CPU Bound process then I/O bound process.
// 3.	Here, first process will get the CPU first, other processes can get CPU only after the current process has finished it’s execution. Now, suppose the first process has large burst time, and other processes have less burst time, then the processes will have to wait more unnecessarily, this will result in more average waiting time, i.e., Convey effect.
// 4.	This effect results in lower CPU and device utilization.
// 5.	FCFS algorithm is particularly troublesome for time-sharing systems, where it is important that each user get a share of the CPU at regular intervals. 
