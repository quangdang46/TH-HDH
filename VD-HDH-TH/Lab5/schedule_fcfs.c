/**
 * schedule_fcfs.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "cpu.h"
#include "schedulers.h"

#define SIZE    100


static int i=0;
Task task[SIZE];
// add a task to the list 
void add(char *name, int priority, int arrival, int burst) {
    task[i].name = name;
    task[i].burst = burst;
    i++;
}

// invoke the scheduler
void schedule(){
    int j=0;
    int time=0;
    float arround=0;
    float aver1;

    float wait=0;
    float aver2;
    for(j=0 ; j < i ; j++) {
        run(&task[j],time,task[j].burst);
        time += task[j].burst;

	arround += time - task[j].arrival;
	wait += time - task[j].burst;
	
    }
	aver1 = arround/8;
	aver2 = wait/8;
	printf("Thoi gian xoay vong trung binh cua cac tien trinh la: %1.2f \n",aver1);
	printf("Thoi gian cho trung binh cua cac tien trinh la: %1.2f \n",aver2);
}
