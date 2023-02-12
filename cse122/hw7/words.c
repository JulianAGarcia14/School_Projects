#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lex_word.h"
#include <string.h>
#include <ctype.h>
#define LEN 4096

//demo program of lexer for words
/*  convert string to lowercase */
void tolowercase(char *s)
{
        while (*s) { 
                *s = tolower(*s);
                s++;
        }
}


void word_dump(char *infile)
{
        
        FILE *in = fopen(infile, "r");
        assert(in);
        char word[LEN];
        int token;

        while (1) {
                switch (token = get_tok(in, word, sizeof(word))) {
                case TOK_WORD:
                        if (strcmp(word, "")) { 
                                tolowercase(word);
                                printf("%s\n", word);
                        }
                        break;
                case TOK_ERR:
                        printf("err: %s\n", word);
                        break;
                case TOK_EOF:
                        return;
                }
        }
}

int main(int argc, char **argv)
{
        if (argc != 2) {
                printf("usage: words filename\n");
                exit(EXIT_FAILURE);
        }
        word_dump(argv[1]);
        
        return 0;



}
