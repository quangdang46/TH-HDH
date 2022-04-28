#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const*argv[])
{
	int n=atoi(argv[1]);
	int m;
	pid_t pid;
	pid = fork();
	if (pid<0) printf("Khong co tien trinh duoc tao ra\n");
	else if (pid==0) 
	{
		printf("%d ",n);
		while (n>1)
		{
			
			if (n%2==0)
			{
				n=n/2;
				printf("%d  ",n);
			}
			else 
			{
				n=3*n+1;
				printf("%d  ",n);
			}
		}
		printf("\n");
	}
	else wait(NULL);
	return 0;
}
