#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#define MAX_THREAD 4
pthread_t th[MAX_THREAD];
pthread_mutex_t mutexBuffer;

sem_t semEmpty;
sem_t semFull;


int buffer[10];
int count = 0;

void* producer(void* args) {
    //lap day du lieu vao
    while (1) {
        //Dua de lieu vao bo nho
        int x = rand() % 100;
        sleep(1);

        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);
        buffer[count++] = x;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);
    }
}

void* consumer(void* args) {
    while (1) {
        int y;
        // Lay du lieu
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        y = buffer[count - 1];
        count--;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semEmpty);

        // Consume
        printf("Data %d\n", y);
        sleep(1);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    pthread_mutex_init(&mutexBuffer, NULL);
    sem_init(&semEmpty, 0, 10);
    sem_init(&semFull, 0, 0);
    int i;
    for (i = 0; i < MAX_THREAD; i++) {
        int ret1=pthread_create(&th[i], NULL, &producer, NULL);
        int ret2=pthread_create(&th[i], NULL, &consumer, NULL);
        if (ret1 != 0){
			printf("Thread producer [%d] created error\n", i);
		}
        if (ret2 != 0)
		{
			printf("Thread consumer [%d] created error\n", i);
		}
    }
    for (i = 0; i < MAX_THREAD; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);
    return 0;
}