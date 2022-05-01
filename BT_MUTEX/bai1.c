#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_THREAD 3
pthread_t tid[MAX_THREAD];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static int balance = 0;
// gui tien

void deposit(int tmp)
{
    pthread_mutex_lock(&mutex);
    balance += tmp;
    pthread_mutex_unlock(&mutex);
}

// rut tien
void withdraw(int tmp)
{
    pthread_mutex_lock(&mutex);
    balance += tmp;
    pthread_mutex_unlock(&mutex);
}

void file(char *s)
{
    int tmp;
    FILE *fp = fopen(s, "r");
    while (fscanf(fp, "%d", &tmp))
    {
        if (tmp > 0)
        {
            deposit(tmp);
        }
        else
        {
            withdraw(tmp);
        }
        if (balance < 0)
        {
            printf("\nWarning: Balance under 0.00\n");
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("\nError: No file name\n");
        return 0;
    }
    int i;
    for (i = 1; i < argc; i++)
    {
        pthread_create(&tid[i - 1], NULL, (void *)file, argv[i]);
    }
    for (i = 1; i < argc; i++)
    {
        pthread_join(tid[i - 1], NULL);
    }
    printf("\nBalance: %d\n", balance);
    pthread_exit(NULL);
    return 0;
}