#include <stdio.h>
#include <string.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/dir.h>
#include <dirent.h>

//int foo(int fd, char* buf, int b_size, int n, int skip);

int main(void)
{
	struct stat statbuf;
	char dirpath[256];
	getcwd(dirpath,256);
	DIR *dir = opendir(dirpath);
	struct dirent *dp;
	char reader[1000];
	for (dp=readdir(dir); dp != NULL ; dp=readdir(dir)){
		stat(dp->d_name, &statbuf);
		int len = strlen(dp->d_name); 
		if(dp->d_name[len-1]=='t' && dp->d_name[len-2]=='x' && dp->d_name[len-3]=='t'){
			int fd = open(dp->d_name, O_RDONLY, 0);
			read(fd,reader,1000);
			close(fd);
			printf("#%s\n",reader);
			write(open("All.txt", O_APPEND ,1),reader,1000);
		}
	}
	return 0;
}
