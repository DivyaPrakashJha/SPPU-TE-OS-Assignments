// Author : Divya Prakash

#include<stdio.h>
#include<stdlib.h>

void binarySearch(int a[], int n, int num){
    int low = 0, high = n, mid = 0;
		
    while(low < high){
        mid = (low + high)/2;

        if (a[mid] == num){
            printf("\nElement Found!!\n");
            break;
        }
        else if (a[mid] < num) low = mid + 1;
        else high = mid;
    }

    if (low >= high) printf("\nElement Not Found!!\n");
}

int main(int argc, char* argv[]){
    printf("Executing Child Process\n");
    
    int a[argc-2];
    printf("\nSorted Array : ");
    for(int i = 1; i < argc-1; i++){
        a[i-1] = atoi(argv[i]);
        printf("%d ", a[i-1]);
    }

    int num = atoi(argv[argc-1]);

    binarySearch(a, argc-2, num);
    
    return 0;
}