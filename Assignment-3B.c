// Author : Divya Prakash

// CPU Scheduling
// Round Robin

#include<stdio.h>

struct Process{
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
};

int min(int a, int b){
    if (a <= b) return a;
    return b;
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

    int timeQuant = 0;
    printf("\nEnter the time quantum for Round-Robin : ");
    scanf("%d", &timeQuant);

    int processesExecuted = 0;
    int time = 0;

    printf("\n\nGantt's Chart\n");
    printf("Time\t Process\n");

    while(processesExecuted < n){
        int flag = 0;
        
        for(int i = 0; i < n; i++){
            if (p[i].arrivalTime <= time && p[i].remainingTime > 0){
                flag = 1;
                int executionTime = min(timeQuant, p[i].remainingTime);

                printf("%d\t %d\n", time, i);

                p[i].remainingTime -= executionTime;
                time += executionTime;

                if (p[i].remainingTime <= 0){
                    p[i].completionTime = time;
                    processesExecuted++;
                }
            }
        }

        if (!flag) time++;
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