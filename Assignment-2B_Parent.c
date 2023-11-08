// Author : Divya Prakash

// Execv System Call

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){
    int n = 0;
    printf("\nEnter the size of the array : ");
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    bubbleSort(a, n);
	
	char* args[n+3];
		
	args[0] = "./child";
	for(int i = 0; i < n; i++){
		args[i+1] = malloc(10);
	    sprintf(args[i+1], "%d", a[i]);
   	}
    	
    int num = 0;
   	printf("Enter the number you want to search : ");
   	scanf("%d", &num);
    	
   	args[n+1] = malloc(10);
   	sprintf(args[n+1], "%d", num);
    	
    args[n+2] = NULL;
	
	int id = fork();
    if (id == 0){
        printf("\n\nTransferring execution to child program using execve system call..\n");
        
        execve(args[0], args, NULL);
    }
    else if (id > 0){
    	printf("\nExecuting Parent Process!!\n");
        printf("Sorted Array : ");
        for(int i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
    }
}

// Steps to execute
// 1) gcc Assignment-2B_Parent.c
// 2) gcc Assignment-2B_Child.c -o child
// 3) ./a.out

