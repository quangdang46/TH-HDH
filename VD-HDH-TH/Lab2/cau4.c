#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const*argv[])
{
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	if (argv[3]=="+")
		printf("Ket qua: %d",add(a,b));
	else if (argv[3]=="-")
		printf("Ket qua: %d",sub(a,b));
	else printf("Doi so truyen khong dung.");
		
	return 0;
}
