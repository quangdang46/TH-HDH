#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#inlude<stdbool.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
prthread_t tid[3];
static int count=0;
bool andy=false;
bool ben=false;
void bid(int tmp)
{
    pthread_mutex_lock(&mutex);
    if(tmp>count){
        count=tmp;
    }
    pthread_mutex_unlock(&mutex);
}

void *file(void *s)
{
    int tmp;
    FILE *fp=fopen(s,"r");
    while(fscanf(fp,"%d",&tmp)){
        //TODO
    }
}

int main(int argc, char **argv){
    if (argc == 1)
    {
        printf("\nError: No file name\n");
        return 0;
    }
    int i;
    for (i=1;i<argc;i++){
        pthread_create(&tid[i-1],NULL,(void *)file,argv[i]);
    }
    for(i=1;i<argc;i++){
        pthread_join(tid[i-1],NULL);
    }
}
