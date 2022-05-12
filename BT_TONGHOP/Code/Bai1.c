#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
 
struct file{
    char fileName[10];
};
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
int balance=0;
int cntFile(char file[]){
    FILE *f=fopen(file,"r");
    int cnt=0;
    int num;
    while(fscanf(f,"%d",&num)){
        //fscanf(f,"%d",&num);
        cnt++;
    }
    return cnt;
}
void *thr1(void *arg){
    struct file *fi=(struct file *)arg;
    FILE *f=fopen(fi->fileName,"r");
    pthread_mutex_lock(&mutex);
    int i;
    for(i=0;i<cntFile(fi->fileName)-1;++i){
        char s[10];
        fgets(s,sizeof(s),f);
        balance+=atoi(s);
    }
    pthread_mutex_unlock(&mutex);
}
int main(int argc,char *argv[]){
    struct file a;
    strcpy(a.fileName,argv[1]);
    struct file b;
    strcpy(b.fileName,argv[2]);
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,thr1,&a);
    pthread_create(&tid[1],NULL,thr1,&b);
	printf("Balance:%d",balance);
 
}