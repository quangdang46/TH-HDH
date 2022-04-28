#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
	int a[100];
	int i,j,k,temp;
	int n;
	//Kiem tra cac doi so nhap vao
	for (i=1; i<argc; i++)
	{
		if (argv[i]<=0 || argv[i]>0)
			a[i]=atoi(argv[i]);

	}
	//Thuat toan sap xep
	for (i=0; i<argc-1; i++)
	{
		for (j=i+1; j<argc; j++)
		{
			if (a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("Day tang la ");
	for (i=1 ;i<argc; i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
}
