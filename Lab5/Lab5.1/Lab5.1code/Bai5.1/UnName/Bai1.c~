#include <stdio.h>
#include <unistd.h>
#include <string.h>
 
int main(int argc, char **argv)
{
    int fp1[2];

    int pid;
	//printf("%d",argc);
    if (argc < 2)
    {
        printf("Doi so thieu.\n");
        return -1;
    }
    if (pipe(fp1) == 0)
    {
        pid = fork();
 
        if (pid < 0)
        {
            printf("Fork failed\n");
            return -1;
        }
        else if (pid == 0)
        {
            close(fp1[1]);
		char buffer[256];
            while (read(fp1[0], &buffer, sizeof(buffer))>0)
            {
                printf("%s\n",buffer);
            }
            close(fp1[0]);
        }
        else
        {
            close(fp1[0]);
            //o doc 1 viet
            int i;
            for (i = 1; i <argc; i++){
                write(fp1[1],&argv[i],sizeof(&argv[i]));       
	    }
            //wait(NULL);
            close(fp1[1]);
        }
    }
    else
    {
        printf("Pipe failed\n");
        return -2;
    }
}
