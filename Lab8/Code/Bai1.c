// C program to demonstrate working of Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex1,mutex2;
void *inle(void *arg)
{
    // wait
    int i;
    for(i=1;i<12;i+=2){
        sem_wait(&mutex2);
        printf("Thred 1:%d\n",i);
        sem_post(&mutex1);
    }

}
void *inchan(void *arg)
{
    // wait
    int i;
    for(i=2;i<11;i+=2){
        sem_wait(&mutex1);
        printf("Thred 2:%d\n",i);
        sem_post(&mutex2);
    }

}
int main()
{
    sem_init(&mutex1, 0, 0);
    sem_init(&mutex2, 0, 1);

    pthread_t t1, t2;
    pthread_create(&t1, NULL, inle, NULL);
    // sleep(2);
    pthread_create(&t2, NULL, inchan, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex1);
sem_destroy(&mutex2);
    return 0;
}
