#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

long int total_point;
void *circle_point(void *param)
{
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
    pthread_exit(0);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Error\n");
        return -1;
    }
    int NUM_THREAD;
    long int count_circle = 0;
    printf("Nhap so thread:");
    scanf("%d", &NUM_THREAD);
    sleep(1);
    pthread_t tid[4] = {0};
    int count[4] = {0};
    total_point = atoll(argv[1]) / NUM_THREAD;
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_THREAD; i++)
        pthread_create(&tid[i], NULL, circle_point, &count[i]);
    for (i = 0; i < NUM_THREAD; i++)
    {
        pthread_join(tid[i], NULL);
        count_circle += count[i];
    }
    double pi = 4.0 * (double)count_circle / (double)total_point / (double)NUM_THREAD;

    printf("PI = %17.15f\n", pi);
    return 0;
}

