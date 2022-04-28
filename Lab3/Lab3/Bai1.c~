#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char *argv[]){
	int n = atoi(argv[1]), s = 0, i;
	pid_t pid;
	pid = fork();
	if (pid < 0){
		printf("Loi\n");
	}else if (pid == 0){
		for (i = 1; i < n; i++){
			if (n % i == 0)
				s += i;
		}
		printf("Sum2=%d\n", s);
	}else{
		wait(NULL);
		for (i = 1; i <= n; i++){
			s += i;
		}
		printf("Sum1 = %d\n",s);
	}
	return 0;
}
