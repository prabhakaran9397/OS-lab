#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	char buf;int n;
	int fd=open("test2.txt",O_RDWR|S_IREAD|S_IWRITE);
	if(fd!=-1)
		printf("test2 opened");
	else
		printf("error");
	int fd1=open("file.txt",O_RDWR|S_IREAD|S_IWRITE);
	if(fd1!=-1)
		printf("file opened");
	else
		printf("error");
	while(read(fd,&buf,1))
	{
		write(fd1,&buf,1);
	}
	write(STDOUT_FILENO,"files copied\n",15);
	close(fd);
	return 0;
}

