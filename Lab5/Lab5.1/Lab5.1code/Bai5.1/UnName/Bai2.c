#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fp1[2], fp2[2];
    int pid;
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
            int buffer;
            close(fp1[1]);
            read(fp1[0], &buffer, sizeof(buffer));
            int cnt = 1, i;
            for (i = 1; i <= buffer; i++)
            {
                cnt *= i;
            }
            printf("%d!=%d\n", buffer, cnt);
            close(fp1[0]);
        }
        else
        {
            close(fp1[0]);
            // o doc 1 viet
            int tmp = atoi(argv[1]);
            write(fp1[1], &tmp, sizeof(tmp));
            close(fp1[1]);
        }
    }
    else
    {
        printf("Pipe failed\n");
        return -2;
    }
}
