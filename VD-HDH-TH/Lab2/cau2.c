#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const*argv[])
{
	int n=atoi(argv[1]);
	int i;

	if (argc==2 && n>0)
	{
		printf("Cac uoc so cua %d la ",n);
		for (i=1; i<=n; i++)
		if (n%i==0)
			printf("%d    ",i);
	}
	else if (argc>2)
		printf("Thua doi so");
	else printf("Khong phai la so nguyen");
	printf("\n");

	return 0;
}
