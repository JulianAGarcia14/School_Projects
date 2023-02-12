#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void) {
        int fd[2];
        pipe(fd);
        dup2(fd[0], STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);

        int i, myint;
        for (i=0; i < 100; i++) {
                write(STDOUT_FILENO, &myint, sizeof(myint));
                read(STDIN_FILENO, &i, sizeof(i));
                fprintf(stderr, "%d\n", myint);
        }

        close(fd[0]);
        close(fd[1]);


}
