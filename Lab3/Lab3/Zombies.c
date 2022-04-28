#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	pid_t pid;
	pid = fork();
	if (pid < 0){
		printf("Loi");
	}
	else if (pid == 0){
		printf("Bat dau tien trinh con\n");
		printf("Thoat tien trinh con\n");
		exit(0);
	}else{
		printf("Bat dau tien trinh cha\n");
		sleep(10);
		printf("Ket thuc tien trinh cha\n");
		exit(0);
	}
}
