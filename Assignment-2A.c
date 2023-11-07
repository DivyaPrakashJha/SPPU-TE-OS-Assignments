// Author : Divya Prakash

#include <stdio.h>
#include<stdlib.h>

void bubbleSort(int n, int arr[]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1]){	
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	printf("\nSorted Array : ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}

int main(){
	int n = 0;
	
	printf("Enter the value of n : ");
	scanf("%d", &n);
	
	int arr[n];
	
	printf("\nEnter the array numbers : ");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	
	int id = fork();
	
	if (id == 0){ // Child Process
		printf("\n\nExecuting Child Process\n");
		printf("Process ID : %d\n", getpid());
		printf("Parent ID : %d\n", getppid());
		
		printf("Original Array : ");
		for(int i = 0; i < n; i++) printf("%d ", arr[i]);
		bubbleSort(n, arr);
	}
	else if (id > 0){ // Parent Process
		wait(NULL);
		printf("\n\nExecuting Parent Process\n");
		printf("Process ID : %d\n", getpid());
		printf("Child ID : %d\n", id);
		
		printf("Original Array : ");
		for(int i = 0; i < n; i++) printf("%d ", arr[i]);
		bubbleSort(n, arr);
	}
	else{
		printf("Child Process cannot be created");
	}
}

// Zombie State : A process which has finished the execution but still has entry in the process table to report to its parent process is known as a zombie process. 
// Orphan State : A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process.

