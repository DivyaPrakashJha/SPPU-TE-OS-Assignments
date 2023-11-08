// Author : Divya Prakash

// Reader-Writer Problem

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int rc = 0;
sem_t m, wrt;

void* reader(int i){
    printf("Reader %d is created!\n", i);

    sem_wait(&m);
        rc++;
        printf("Reader %d is reading\n", i);

        if (rc == 1) sem_wait(&wrt);
    sem_post(&m);

    sem_wait(&m);
        rc--;
        printf("Reader %d has finished reading\n", i);

        if (rc == 0) sem_post(&wrt);
    sem_post(&m);
}

void* writer(int i){
    printf("Writer %d is created\n", i);
    sleep(5);

    sem_wait(&wrt);
        printf("Writer %d is writing\n", i);
    sem_post(&wrt);

    printf("Writer %d has completed writing\n", i);
}

int main(){
    pthread_t r[6], w[6];

    sem_init(&m, 0, 1);
    sem_init(&wrt, 0, 1);

    for(int i = 0; i < 6; i++){
        pthread_create(&w[i], NULL, writer, i);
        sleep(1);
        pthread_create(&r[i], NULL, reader, i);
        sleep(1);
    }

    for (int i = 0; i < 6; i++) {
        // Wait for the threads to complete.
        pthread_join(w[i], NULL);  
        pthread_join(r[i], NULL);
    }
}

