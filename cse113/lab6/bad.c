#include <stdio.h>

void
print_scrambled(char *message)
{


  int i = 1;
 //corrected Julian Garcia 03/24/18
//if(message) {

  do {
	 if(message) {
	//corrected Julian Garcia
   	printf("%c", (message)+i);
}
} while (*++message);




	printf("\n");



}

int
main()
{
  char * message = NULL;
  char * msg = "Hello, world.";

  print_scrambled(msg);
  print_scrambled(message);

  return 0;
}

//gdb -q --argu ./... # for factorials
//bt full
