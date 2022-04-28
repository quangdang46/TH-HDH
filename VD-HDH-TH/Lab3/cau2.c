#include <stdio.h>

int main (int argc, char const*argv[])
{
	int re;
	printf("Loi goi he thong thuc hien lenh ls \n");
	re = system("ls");
	if (re != -1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh ls -a\n");
	re = system("ls -a");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh mkdir \n");
	re = system("mkdir QA");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh cd QA \n");
	re = system("cd QA");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh tao file1 \n");
	re = system("touch file1");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh copy file2 \n");
	re = system("cp file1 file2");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh move \n");
	re = system("mv file1 file2");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh tao QA2 \n");
	re = system("mkdir QA2");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh xoa QA2 \n");
	re = system("rmdir QA2");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh tao file3 \n");
	re = system("gedit file3.txt");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh dem so ki tu trong file3 \n");
	re = system("wc file3");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh xoa file3 \n");
	re = system("rm file3");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	printf("Loi goi thuc hien lenh cd QA \n");
	re = system("cd QA");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	
	printf("Loi goi thuc hien lenh clear man hinh \n");
	re = system("clear");
	if (re!=-1)
		printf("Loi goi da thuc hien xong\n");

	return 0;
}

	

	
	
	
