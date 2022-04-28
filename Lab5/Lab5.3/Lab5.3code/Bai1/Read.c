
//read
// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
// structure for message queue
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message;
int main()
{
	key_t key;
	int msgid;
// ftok to generate unique key
	key = ftok("msg.txt",1);
// msgget creates a message queue
// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
// msgrcv to receive message
	msgrcv(msgid, &message, sizeof(message),1,0);
    int cnt=1,i;
    int n=atoi(message.mesg_text);
    for(i=1;i<=n;i++){
        cnt*=i;
    }
    printf("%d!=%d",n,cnt);
// to destroy the message queue
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}
 
