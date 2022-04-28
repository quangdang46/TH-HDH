#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex1, mutex2;
void* W(void* arg)
{
	
	sem_wait(&mutex1);
	printf("Vermont toi.\n");
	
	//critical section
	sleep(1);
	

	sem_post(&mutex2);
	printf("Vermont da qua cau.\n");
}

void* E(void* arg)
{
	
	sem_wait(&mutex2);
	printf("Nguoi nguoi toi.\n");
	

	sem_post(&mutex1);
	printf("Nguoi da qua cau.\n");
}

int main(void)
{
	pthread_t W1, W2, W3, W4, W5, E1, E2, E3, E4;
	sem_init(&mutex1, 0, 1);
	sem_init(&mutex2, 0, 0);
	
	pthread_create(&W1,NULL,W,NULL);
	pthread_create(&E1,NULL,E,NULL);

	
	pthread_join(W1,NULL);
	pthread_join(E1,NULL);



	sem_destroy(&mutex1);
	sem_destroy(&mutex2);
	
}

	

