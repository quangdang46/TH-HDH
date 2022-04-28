#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>

sem_t m1, m2, m3;
void *taosuon(void *argv){
	sem_wait(&m1);
	printf("Tao suon xe\n");
	sem_post(&m2);
}
void *taobanh(void *argv){
	int i;
	sem_wait(&m2);
	for(i=0;i<4;i++){
		printf("Tao banh xe\n");
	}
	sem_post(&m3);
}
void *lapxe(void *argv){
	sem_wait(&m3);
	printf("Lap rap xe\n");
	sem_post(&m1);
}

void main()
{
    int n,i;
    printf("Nhap so luong xe: ");
    scanf("%d", &n);

    sleep(2);
    for(i=0;i<n;i++){
        sem_init(&m1,0,1);
        sem_init(&m2,0,0);
        sem_init(&m3,0,0);
        
        pthread_t t1;
        pthread_t t2;
        pthread_t t3;
        pthread_create(&t1, NULL, taosuon, NULL);
        pthread_create(&t2, NULL, taobanh, NULL);
        pthread_create(&t3, NULL, lapxe, NULL);
        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
        pthread_join(t3, NULL);
    }
	
	sem_destroy(&m1);
	sem_destroy(&m2);
	sem_destroy(&m3);
}
