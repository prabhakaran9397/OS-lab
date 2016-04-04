#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
static char message[]="hello";
int main()
{
	int fd;
	fd=open("file.txt",O_RDWR|S_IREAD|S_IWRITE);
	if(fd!=-1)
	{
		printf("file opened for read or write access\n");
		write(fd,message,sizeof(message));
		lseek(fd,0,0);
	}
	else
		printf("error");
	close(fd);
	return 0;
}

