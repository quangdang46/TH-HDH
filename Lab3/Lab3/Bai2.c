#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    pid_t pid_C;
    pid_C = fork();
    if (pid_C == 0){
        pid_t pid_H;
        pid_H = fork();
        if (pid_H > 0){
            printf("C) My PID: %d, my parent PID: %d\n", getpid(), getppid());
            wait(NULL);
        }
        else if (pid_H == 0){
            printf("H) My PID: %d, my parent PID: %d\n", getpid(), getppid());
        }
    }else if (pid_C > 0){
        pid_t pid_B;
        pid_B = fork();
        if (pid_B > 0){
            printf("A) My PID: %d, my parent PID: %d\n", getpid(), getppid());
            wait(NULL);
        }
        else if (pid_B == 0){
            pid_t pid_E;
            pid_E = fork();
            if (pid_E > 0){
                wait(NULL);
                pid_t pid_D;
                pid_D = fork();
                if (pid_D > 0){
                    printf("B) My PID: %d, my parent PID: %d\n", getpid(), getppid());
                    wait(NULL);
                }
                else if (pid_D == 0){
                    printf("D) My PID: %d, my parent PID: %d\n", getpid(), getppid());
                }
            }
            else if (pid_E == 0){
                printf("E) My PID: %d, my parent PID: %d\n", getpid(), getppid());
            }
        }
        wait(NULL);
    }
}

