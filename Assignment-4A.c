// Author : Divya Prakash

// Producer Consumer Problem

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

pthread_mutex_t m;
sem_t full, empty;

int buff[6];

void* producer(){
    printf("Producer is Created.\n");
    sleep(1);

    int i = 0;
    while(1){
        sem_wait(&empty);
            pthread_mutex_lock(&m);
                int n = random()%10;
                buff[i++] = n;
                printf("Number %d is added at position %d by producer.\n", n, i-1);
                i%=6;
            pthread_mutex_unlock(&m);
        sem_post(&full);
        sleep(2);
    }
}

void* consumer(){
    printf("Consumer is Created.\n");
    sleep(1);

    int i = 0;
    while (1){
        sem_wait(&full);
            pthread_mutex_lock(&m);
                int key = buff[i++];
                printf("Number %d is consumed from position %d by consumer.\n", key, i-1);
                i%=6;
            pthread_mutex_unlock(&m);
        sem_post(&empty);
        sleep(2);
    }
}

int main(){
    pthread_mutex_init(&m, NULL);

    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 6);

    pthread_t prod, cons;

    pthread_create(&prod, NULL, producer, NULL);
    sleep(2);
    pthread_create(&cons, NULL, consumer, NULL);
    sleep(2);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
}