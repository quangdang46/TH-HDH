#include<stdio.h>
#include <string.h>
int check(char x[])
{
    int i;
    for (i = 0; i < strlen(x); i++)
    {
        if ((x[i] >= 97 && x[i] <= 122) || (x[i] >= 65 && x[i] <= 90))
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc,char **argv){
	int i;
	if(argc>2 || check(argv[1])==0){
		printf("Loi\n");
	}else{
		printf("Cac uoc so cua %s la ",argv[1]);
		int res=atoi(argv[1]);		
		for(i=1;i<=res;i++){
			if(res%i==0) printf("%i ",i);
		}

		printf("\n");
		printf("%i = ",res);
		int tmp=2;
		while(res!=1){
			if(res%tmp==0 && res/tmp!=1){
				printf("%i*",tmp);
				res/=tmp;
			}else if(res%tmp==0 && res/tmp==1){
				printf("%i",tmp);
				res/=tmp;			
			}else tmp+=1;		
		}	
			
	}
	printf("\n");
	return 0;
		
}
