// WAP to implement the priority scheduling 
// Theory
// Priority scheduling is one of the most common scheduling algorithms in batch systems. Each process is assigned a priority. Process with the highest priority is to be executed first and so on. 
// Processes with the same priority are executed on first come first served basis. Priority can be decided based on memory requirements, time requirements or any other resource requirement.

#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,i,j,k,temp,p,q,flag=0;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int p_id[n],p_bt[n],p_at[n],p_wt[n],p_tat[n],p_pri[n];
    printf("Enter the arrival time and burst time of each process\n");
    for(i=0;i<n;i++){
        scanf("%d%d",&p_at[i],&p_bt[i]);
        p_id[i]=i+1;
        p_pri[i]=p_bt[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p_pri[i]>p_pri[j]){
                temp=p_pri[i];
                p_pri[i]=p_pri[j];
                p_pri[j]=temp;
                temp=p_bt[i];
                p_bt[i]=p_bt[j];
                p_bt[j]=temp;
                temp=p_at[i];
                p_at[i]=p_at[j];
                p_at[j]=temp;
                temp=p_id[i];
                p_id[i]=p_id[j];
                p_id[j]=temp;
            }
        }
    }
    p=p_at[0];
    for(i=0;i<n;i++){
        p_wt[i]=p-p_at[i];
        p+=p_bt[i];
        p_tat[i]=p_wt[i]+p_bt[i];
    }
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p_id[i],p_at[i],p_bt[i],p_wt[i],p_tat[i]);
    }
    printf("\n\n");
    printf("Process ID\tPriority\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",p_id[i],p_pri[i],p_wt[i],p_tat[i]);
    }
}

// Output:
// Image

// Advantages
