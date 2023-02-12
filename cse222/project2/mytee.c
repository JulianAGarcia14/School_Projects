/*******************************
/	filename: mytee.c
/	description: Emulates the tee command in linux using File I/O system calls.
/	author: Garcia, Julian
/	class: cse222
/	instructor: Tong
/	assignment: Project 2
/	due: Feb 13
*********************************/

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 4096

void err_sys(const char* x)
{
    perror(x);
    exit(1);
}

int main(int argc, char *argv[]) {

	 int opt;
	 int flaga = 0;
	 char *filename;
	 while((opt = getopt(argc, argv, ":a")) != -1)
	 {
    		switch(opt)
  		{
			case 'a':
	    			printf("option: %c\n", opt);
				flaga = 1;
	    			break;
			case ':':
	    			printf("option needs a value\n");
	    			break;
			case '?':
	    			printf("unknown option: %c\n", optopt);
	    			break;
    		}

	}
	// optind is for the extra arguments
	// which are not parsed
	for(; optind < argc; optind++){
		filename = argv[optind];
	}

	int fd;
	switch(flaga)
	{
		case 0:
			fd = open(filename, O_RDWR | O_CREAT | O_TRUNC);
			if (fd < 0)
			{
				perror("c1");
				exit(1);
			}
			break;
		case 1:
			fd = open(filename, O_RDWR | O_APPEND);
			if (fd < 0)
			{
				perror("c1");
				exit(1);
			}
			printf("opened the fd = %d\n", fd);
			break;
	}


	int n;
	char buf[BUFFSIZE];

	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
		if(write(STDOUT_FILENO, buf, n) != n) {
			err_sys("write error");
		} else if(write(fd, buf, n) !=n) {
			err_sys("write error");
		}
	}
	if(n < 0) {
		err_sys("read error");
	}

	if (close(fd) < 0)
	{
    		perror("c1");
    		exit(1);
	}

	return 0;
}
