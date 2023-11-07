// Author : Divya Prakash

// CPU Scheduling
// Shortest Job First (Preemptive) - Shortest Remaining Time First

#include<stdio.h>
#include<stdlib.h>

struct Process{
    int processID;
    int arrivalTime;
    int burstTime; // CPU time required for its execution
    int remainingTime;
    int completionTime;
};

int findShortestJob(struct Process p[], int n, int currTime){
    
    int shortestTime = 10000;
    int shortestJob = 0;

    for(int i = 0; i < n; i++){
        if (p[i].arrivalTime <= currTime && p[i].remainingTime > 0){
            if (p[i].remainingTime < shortestTime){
                shortestTime = p[i].remainingTime;
                shortestJob = i;
            }
        }
    }

    return shortestJob;
}

int main(){
    int n = 0;
    printf("Enter the number of Processes : ");
    scanf("%d", &n);

    struct Process p[n];

    for(int i = 0; i < n; i++){
        p[i].processID = i;

        printf("\nEnter the arrival time of process %d : ", i);
        scanf("%d", &p[i].arrivalTime);
        printf("Enter the burst time of process %d : ", i);
        scanf("%d", &p[i].burstTime);

        p[i].remainingTime = p[i].burstTime;
        p[i].completionTime = 0;
    }

    int processesExecuted = 0;
    int time = 0;

    printf("\n\nGantt's Chart\n");
    printf("Time\t Process\n");
    while(processesExecuted < n){
        int shortestJob = findShortestJob(p, n, time);
        printf("%d\t %d\n", time, shortestJob);

        p[shortestJob].remainingTime--;
        
        time++;
        if (p[shortestJob].remainingTime == 0){
            p[shortestJob].completionTime = time;
            processesExecuted++;
        }
    }

    int totalTAT = 0, totalWT = 0;

    printf("\nPID\t Arr\t Burst\t Comp\t T.A.T\t Wait\n");
    for(int i = 0; i < n; i++){
        int turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        int waitingTime = turnaroundTime - p[i].burstTime;

        totalTAT += turnaroundTime;
        totalWT += waitingTime;

        printf("%d\t %d\t %d\t %d\t %d\t %d\n", p[i].processID, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, turnaroundTime, waitingTime);
    }

    printf("\nAverage Turnaround Time : %f\n", totalTAT/(1.0*n));
    printf("Average Waiting Time : %f\n", totalWT/(1.0*n));
}