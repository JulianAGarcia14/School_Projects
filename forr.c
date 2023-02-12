/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

   int i;

   int count = 2;

   printf("A\n");

   fork();

   printf("B\n");

   for (i=0; i<count; i++) {

      if(fork() != 0)

               printf("A\n");

      else

              printf("C\n");

     }

   printf("C\n");
}
