#include<sys/file.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/dir.h>
#include<dirent.h>
#include<stdio.h>
int main(void)
{
	int x = creat("file2.txt",0777);
	int y = open("file.txt",O_RDONLY,0);
	x = open("file2.txt",O_RDWR,0);
	char s[]="h";
	char *p=s;
	while(read(y,p,1))
		write(x,p,1);
	close(x);
	return 0;
}
