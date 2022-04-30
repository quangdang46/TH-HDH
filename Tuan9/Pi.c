#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
#define MAX_THREAD 2
 
pthread_t tid[MAX_THREAD]={0};
/*Counter la bien toan cuc duoc 2 thread su dung*/
int counter;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   //khai bao mutex
long int total_point;
long int count_circle = 0;
 
void *threadFunc(void *param)
{
	pthread_mutex_lock(&mutex);
    int *pcount = (int *)param;
    int i;
    for (i = 0; i < total_point; i++)
    {
        double x = (double)rand() / (double)RAND_MAX;
        double y = (double)rand() / (double)RAND_MAX;
        double r = x * x + y * y;
        if (r <= 1)
            *pcount = *pcount + 1;
    }
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
 
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    total_point = atoll(argv[1]) / MAX_THREAD;
	int i = 0;
	int ret = 0;
    int cnt[2]={0};
	for (i = 0; i < MAX_THREAD; i++)
	{
		ret = pthread_create(&(tid[i]), NULL, threadFunc,&cnt[i]);
		if (ret != 0)
		{
			printf("Thread [%d] created error\n", i);
		}
	}
 
    for (i = 0; i < MAX_THREAD; i++)
    {
        pthread_join(tid[i], NULL);
        count_circle += cnt[i];
    }
    double pi = 4.0 * (double)count_circle / (double)total_point / (double)MAX_THREAD;
    printf("PI = %f\n", pi);
	return 0;
}