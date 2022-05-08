#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/ipc.h>
#include<sys/types.h>
#include <sys/msg.h>
#include <string.h>
#include <semaphore.h> 
#include <unistd.h> 
#define BUFFER_SIZE 100
// Cau truc data de luu du lieu lay tu file
typedef struct data {
	int value[BUFFER_SIZE]; //cac gia tri cua file
	int length;	// do lon cua mang value
	char filename[BUFFER_SIZE]; // Ten file truyen vao
	long mesg_type; 	//loai message
	char mesg_txt[100];
} data;
//Cau truc mesg_buffer dung thuc hien gui tin nhan den chu dau gia cho option 2
struct mesg_buffer {
	long mesg_type; 	//loai message
	char won[BUFFER_SIZE];	//Luu tru ten cua nguoi thang cuoc dau gia
	int money;	//Luu so tien dau gia cuoi cung
} message;

void InDuLieu(data tmp){
	printf("Nguoi dau gia: %s\n",tmp.filename);
	printf("Du lieu:");
	int j;
	for(j=0;j<tmp.length;j++){
		printf("%d ",tmp.value[j]);
	}
	printf("\n");
}
int main()
{
	//Option 1: Nhan thong tin gui tu daugia, xuat thong tin bao gom: Ten nguoi gui, cac chi so value nhan dc.
	key_t key =ftok("msg.txt",1);
	int msgid = msgget(key, 0666 | IPC_CREAT);
	while(1){
		data temp;
		msgrcv(msgid, &temp, sizeof(temp), 1, 0);
		InDuLieu(temp);
		if(strcmp(temp.mesg_txt,"Exit")==0){
			break;
		}
	}
	msgctl(msgid, IPC_RMID, NULL);
	//Option 2: Nhan thong tin gui tu daugia, xuat thong tin bao gom: Ten nguoi thang dau gia, so tien sau cung cua dau gia.
	return 0;
}
