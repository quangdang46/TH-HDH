#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
	int n=atoi(argv[1]);
	int t=0,i,s=0;
	pid_t pid;
	pid = fork();
	
	//neu pid < 0 khong co tien trinh duoc tao
	if (pid < 0) printf("Khong co tien trinh nao dc tao\n");
	else if (pid == 0)//Tien trinh cha thuc hien la cau a	
	{
		wait(NULL);
		
		for (i=1; i<=n; i++)
		{
			s=s+i;
		}
		printf("ID Tien trinh cha: %d\n",getpid());
		printf("Tien trinh cha: %d\n",s);
	}
	else //Tuc la pid > 0 la tien trinh con thuc hien
	{
		
		for (i=1; i<=n; i++)
		{
			
			if (n%i==0)
				t=t+i;
		}
		printf("ID Tien trinh con: %d\n",getpid());
		printf("Tien trinh con: %d\n",t);
	}
	return 0;
}
