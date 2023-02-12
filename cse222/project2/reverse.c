/*******************************
/	filename: reverse.c
/	description: Takes a file, reverses it, and sends the output to another file
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
#include <sys/stat.h>
#include <unistd.h>


void err_sys(const char* x)
{
    perror(x);
    exit(1);
}


int main(int argc, char *argv[]) {

         if(argc != 3) {
                 printf("Usage: -<source> <destination>\n");
                 exit(1);
         }


	int fd;

        int source;

        if ((source = open(argv[1], 0400)) < 0) { //read permission for user on source
                err_sys("Open error source");
        }

        if ((fd = creat(argv[2], 0700)) < 0) { //rwx permission for user on dest
                err_sys("Creat error dest");
        }

        char buf;

        /*
	int n;

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
        */
        int filesize;
        filesize = lseek(source, 0, SEEK_END); //filesize is lastby +offset
        printf("Source file size is %d\n", filesize);

        int i, m;
        for (i = filesize - 1; i >= 0; i--) { //read byte by byte from end
                lseek(source, i, SEEK_SET);

                m = read(source, &buf, 1);

                if (m != 1) {
                        err_sys("can't read 1 byte");
                }

                m = write(fd, &buf, 1);

                if (m != 1) {
                        err_sys("can't write 1 byte");
                }

        }




        if (close(source) < 0)
        {
                err_sys("Close error");
        }

	if (close(fd) < 0)
	{
    		err_sys("Close error");
	}



	return 0;
}
