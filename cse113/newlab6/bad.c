#include <stdio.h>

void
print_scrambled(char *message)
{
  //corrected Julian Garcia 10/28/2018
  int i = 0;
  //int i = 3;
  do {
    printf("%c", (*message)+i);
  } while (*message++);
  printf("\n");
}

int
main()
{
  char * message = NULL;
  char * msg = "Hello, world.";
  //corrected Julian Garcia 10/28/2018
  message = msg;

  print_scrambled(msg);
  print_scrambled(message);

  return 0;
}
