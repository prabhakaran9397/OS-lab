#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int fd;
	fd=creat("file.txt",S_IREAD|S_IWRITE);
	if(fd==-1)
		printf("erroe");
	else
		printf("file is created");
	close(fd);
	return 0;
}

