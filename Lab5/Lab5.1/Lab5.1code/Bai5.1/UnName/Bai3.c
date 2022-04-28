#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fp1[2], fp2[2];
    int pid;
    char arr[argc + 1];
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
            char buffer[100];
            close(fp1[1]);
            char arr[100];
            int cnt = 0;

		fflush(stdin);
		//read(fp1[0], &buffer, sizeof(buffer))	;
		//printf("%s",buffer);
		//scanf("%s%s%s",arr[0],arr[1]),arr[2]);
            while (read(fp1[0], &buffer, sizeof(buffer))!= 0)
            {
		strcpy(arr[cnt],buffer);
		cnt++;
		//printf("%s",buffer);
            }
/*
            switch(arr[2]){
                case '+':
                    printf("%d+%d=%d\n",atoi(arr[0]),atoi(arr[1]),atoi(arr[0]) + atoi(arr[1]));
                    break;
                case '-':
                    printf("%d-%d=%d\n",atoi(arr[0]),atoi(arr[1]),atoi(arr[0]) - atoi(arr[1]));
                    break;
                case '*':
                    printf("%d*%d=%d\n",atoi(arr[0]),atoi(arr[1]),atoi(arr[0]) * atoi(arr[1]));
                    break;
                case '/':
                    if(atoi(arr[1])==0){
                        printf("Khong chia duoc cho 0\n");
                    }else{
                        printf("%d/%d=%d\n",atoi(arr[0]),atoi(arr[1]),atoi(arr[0]) / atoi(arr[1]));
                    }
                    break;
                default:
                    printf("Khong co toan tu\n");
                    break;
            }
*/
            close(fp1[0]);
        }
        else
        {
            close(fp1[0]);
            int i;
		fflush(stdin);
            for (i = 1; i < argc; i++)
            {
                write(fp1[1], argv[i], strlen(argv[i]));
            }
            close(fp1[1]);
        }
    }
    else
    {
        printf("Pipe failed\n");
        return -2;
    }
}
