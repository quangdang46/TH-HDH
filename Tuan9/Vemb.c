#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
pthread_mutex_t a_mutex; // dong bo
static int sove = 0;
void *thr1()
{
    FILE *out = fopen("sove.txt", "r");
    fscanf(out, "%d", &sove);
    fclose(out);
}
void *thr2()
{
    pthread_mutex_lock(&a_mutex);
    if (sove == 0)
    {
        printf("Da het ve,khong the mua tiep\n");
    }
    int tmp;
    FILE *out = fopen("daily1.txt", "r");
    while (fscanf(out, "%d", &tmp)!=EOF)
    {
        if (tmp < sove)
        {
            printf("Dat mua thanh cong dai li 1 voi so ve %d\n", tmp);
            sove -= tmp;
        }
        else
        {
            printf("Khong dat mua thanh cong dai li 1 voi so ve %d\n", tmp);
        }
    }
    fclose(out);
    sleep(5);
    pthread_mutex_unlock(&a_mutex);
    pthread_exit(NULL);
}
void *thr3()
{
    pthread_mutex_lock(&a_mutex);
    int tmp;
    FILE *out = fopen("daily2.txt", "r");
    if (sove == 0)
    {
        printf("Da het ve,khong the mua tiep\n");
    }
    while (fscanf(out, "%d", &tmp)!=EOF)
    {
        if (tmp < sove)
        {
            printf("Dat mua thanh cong dai li 2 voi so ve %d\n", tmp);
            sove -= tmp;
        }
        else
        {
            printf("Khong dat mua thanh cong dai li 2 voi so ve %d\n", tmp);
        }
    }
    fclose(out);
    sleep(5);

    pthread_mutex_unlock(&a_mutex);
    pthread_exit(NULL);
}
int main()
{
    int res = pthread_mutex_init(&a_mutex, NULL);
    // a_mutex = PTHREAD_MUTEX_INITIALIZER;
    int i;
    pthread_t tid[3];
    int status, *pstatus = &status;
    pthread_create(&tid[0], NULL, thr1, NULL);
    if (pthread_join(tid[0], (void **)pstatus) == 0)
    {
        pthread_create(&tid[1], NULL, thr2, NULL);
        pthread_join(tid[1], (void **)pstatus);
        sleep(5);
        pthread_create(&tid[2], NULL, thr3, NULL);
        pthread_join(tid[2], (void **)pstatus);
    }

    return 0;
}