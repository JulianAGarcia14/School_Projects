#include <stdio.h>
#include <stdlib.h> /* atoi */
#include <unistd.h> /* getopt and optarg */

int main(int argc, char **argv)
{
        if (argc != 5) {
                printf("usage: %s -a INTEGER -b INTEGER\n", argv[0]);
                return -1;
        }

        unsigned a = -1;
        unsigned b = -1;
        int c;

        /* pass a string of options to getopt
         * the colon after a letter signifies that the option expects an argument
         */

        while((c = getopt(argc, argv, "a:b:h")) != -1) {
                switch(c) {
                case 'a':
                        a = (unsigned)atoi(optarg);
                        break;
                case 'b':
                        b = (unsigned)atoi(optarg);
                        break;
                case 'h':
                        printf("usage: %s -a INTEGER -b INTEGER\n", argv[0]);
                        return 0;
                default:
                        printf("something went wrong\n");
                        return -1;
                }
        }

        /* if this prints -1 forgot to set options on the command line */
        printf("a = %u\n", a);
        printf("b = %u\n", b);

        return 0;
}
