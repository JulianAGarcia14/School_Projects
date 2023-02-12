/*******************************
/	filename: shell.c
/	description: Emulates a shell
/	author: Garcia, Julian
/	class: cse222
/	instructor: Tong
/	assignment: Project 3
/	due: March 24
*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

void errorfound(char *ch) {
   printf("cse222: %s ERROR \n", ch);
}

int getin(char *ch) {
   char a;
   int num = 0;

   while (((a = getchar()) != '\n') && (num < MAX_LINE)) {
       ch[num++] = a;
   }

   if (num == MAX_LINE && a != '\n') {
       errorfound("Exceeds amount of maximum commands");
       num = -1;
   } else {
       ch[num] = 0;
   }
   while (a != '\n') a = getchar();
   return num;
}

void printhist(char hist[][MAX_LINE + 1], int histcnt) {
   if (histcnt == 0) {
       errorfound("No history yet");
       return;
   }

   int i, j = 10;
   for (i = histcnt; i > 0 && j > 0; i --, j--) {
       printf("%4d\t%s\n", i, hist[i % 10]);
   }
}

int parse(char *buffer, int length, char* args[]) {
   int args_num = 0;
   int last = -1;
   int i;
   args[0] = NULL;
   for (i = 0; i <= length; ++i) {
       if (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i]) {
           continue;
       } else {
           if (last != i-1) {
               args[args_num] = (char*)malloc(i-last);
               if (args[args_num] == NULL) {
                   errorfound("Memory allocation error: Unable to allocate");
                   return 1;
               }
               memcpy(args[args_num], &buffer[last+1], i-last-1);
               args[args_num][i-last] = 0;
                   args[++args_num] = NULL;
           }
           last = i;
       }
   }
   return args_num;
}

int numm(char *a) {
   int length = strlen(a), i, answer = 0;
   for (i = 0; i < length; i++) {
       if (a[i] > '9' || a[i] < '0') return -1;
       answer = answer * 10 + a[i] - '0';
   }
   return answer;
}

int main(void) {

   char *args[MAX_LINE/2 + 1]; /* command line arguments */
   int sr = 1; /* flag to determine when to exit program */

   char history[10][MAX_LINE + 1];
   int histcount = 0;

   char buffer[MAX_LINE + 1];
   memset(buffer, 0, sizeof(buffer));
   int length, args_num;

   while (sr) {
       printf("cse222>");
       fflush(stdout);

       /**
       * After reading user input, the steps are:
       * (1) fork a child process using fork()
       * (2) the child process will invoke execvp()
       * (3) if command included &, parent will invoke wait()
       */

       length = getin(buffer);
       if (length == -1) continue;

       if (strcmp(buffer, "!!") == 0) {
           if (histcount > 0) {
               memcpy(buffer, history[histcount % 10], MAX_LINE + 1);
               length = strlen(buffer);
           } else {
               errorfound("History has no commands");
               continue;
           }
       }

       args_num = parse(buffer, length, args);

       if (args_num == 0) continue;

       if (strcmp(args[0], "!") == 0) {
           int temp = numm(args[1]);
           if (temp <= 0 || temp < histcount - 9 || temp > histcount) {
               errorfound("Command is not in History");
               continue;
           } else {
               memcpy(buffer, history[temp % 10], MAX_LINE + 1);
               length = strlen(buffer);
               args_num = parse(buffer, length, args);
           }
       }

       if (strcmp(args[0], "exit") == 0) {
           sr = 0;
           continue;
       }

       if (strcmp(args[0], "history") == 0) {
           printhist(history, histcount);
           continue;
       }

       histcount ++;
       memcpy(history[histcount% 10], buffer, MAX_LINE + 1);

       int background = 0;
       if (strcmp(args[args_num-1], "&") == 0) {
           background = 1;
           args[--args_num] = NULL;
       }

       pid_t pid = fork();
       if (pid < 0) {
           errorfound("Fork process error");
           return 1;
       }

       int now;

       if (pid == 0) {
           now = execvp(args[0], args);
           if (now == -1) {
               errorfound("Command failed to execute");
           }
           return 0;
       } else {
           if (background) {
               printf("pid #%d running in background %s\n", pid, buffer);
           } else {
               wait(&now);
           }
       }

   }

   return 0;
}
