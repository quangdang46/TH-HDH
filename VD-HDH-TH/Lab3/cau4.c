#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	pid_t child_pid = fork(); 

	// Parent process 
	if (child_pid > 0) 
		sleep(40); 

	// Child process 
	else		
		sleep(10);

	return 0; 
} 
