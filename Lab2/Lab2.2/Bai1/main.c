#include<stdio.h>
int main(int argc,char **argv){
	int sum=0,i;
	if(argc>2) printf("co qua nhieu doi so\n");
	else if(argv[1]<0) printf("truyen vao so nguyen am\n");
	else{
		for(i=1;i<atoi(argv[1]);i++){
			sum+=i;
		}
		printf("S = %i\n",sum);	
	}
	return 0;
		
}
