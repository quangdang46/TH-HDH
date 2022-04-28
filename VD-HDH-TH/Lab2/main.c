#include <stdio.h>
#include <stdlib.h>

int main (int argc, char const *argv[])
{
	int n=atoi(argv[1]);//Tham so thu nhat la tham so minh can
	int i,c=0,s=0;
	
	if (n>0 && argc==2)//Neu nhiu hon 2 doi so nhap vao thi ko thoa
	{
		for (i=0; i<=n; i++)
			s=s+i;
		printf("S = %d\n",s);
	}
	
	else if (argc>2)//nhap nhieu hon 1 so se ko tinh duoc
	{
		printf("Co qua nhieu doi so\n");
	}
	else printf("Doi so khong phai la so nguyen duong\n");
		
	
	return 0;

}	
