// Author : Divya Prakash

// Banker's Algorithm - Deadlock Avoidance Algorithm

#include<stdio.h>
#include<stdlib.h>

void printMatrix(int* a, int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", *(a+i*c + j));
        }
        printf("\n");
    }
}

int main(){
    int numProc = 0, numRes = 0; 
    printf("Enter the number of processes : ");
    scanf("%d", &numProc);
    printf("Enter the number of resources : ");
    scanf("%d", &numRes);

    int allocation[numProc][numRes];
    int maximum[numProc][numRes];
    int need[numProc][numRes];

    int available[numRes];
    int safeSeq[numProc];
    int completed[numProc];
    for(int i = 0; i < numProc; i++) completed[i] = 0;

    printf("\nEnter the Allocation Matrix : ");
    for(int i = 0; i < numProc; i++){
        for(int j = 0; j < numRes; j++){
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter the Maximum Matrix : ");
    for(int i = 0; i < numProc; i++){
        for(int j = 0; j < numRes; j++){
            scanf("%d", &maximum[i][j]);
        }
    }

    printf("\nEnter the Available Resources : ");
    for(int i = 0; i < numRes; i++){
        scanf("%d", &available[i]);
    }

    for(int i = 0; i < numProc; i++){
        for(int j = 0; j < numRes; j++){
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    int counter = 0;
    while(counter < numProc-1){
        printf("\n\nAllocation Matrix\n");
        printMatrix((int *)allocation, numProc, numRes);

        printf("Maximum Matrix\n");
        printMatrix((int *)maximum, numProc, numRes);
        
        printf("Need Matrix\n");
        printMatrix((int *)need, numProc, numRes);
        
        printf("\nAvailable Resources\n");
        for(int i = 0; i < numRes; i++){
            printf("%d ", available[i]);
        }

        int state = 0;
        for(int i = 0; i < numProc; i++){
            if (!completed[i]){
                int flag = 1;
                for(int j = 0; j < numRes; j++){
                    if (available[j] < need[i][j]){
                        flag = 0;
                        break;
                    }    
                }
                
                if (flag){
                    state = 1;
                    printf("\n\n** Process %d is executed\n", i+1);
                    safeSeq[counter] = i+1;
                    completed[i] = 1;
                    counter++;
                    
                    for(int j = 0 ; j < numRes; j++){
                        available[j] += allocation[i][j];
                        allocation[i][j] = 0;
                        maximum[i][j] = 0;
                        need[i][j] = 0;
                    }
                }
            }
        }

        if (!state) break;
    }

    if (counter == numProc){
        printf("\nThe system is in a safe state!!\n SAFE SEQUENCE : ");
        for(int i = 0; i < counter; i++){
            printf("%d ", safeSeq[i]);
        }
    }
    else{
        printf("The system is in an unsafe state!!\n");
    }   
}