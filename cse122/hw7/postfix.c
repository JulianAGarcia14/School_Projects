#include "lex.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 512   //max chars in number, increase as necessary

int calc(void)
{
        int token;
        char num[MAX_NUM];
        char c;

        while (1) {
                switch (token = get_tok(num, sizeof(num))) {
                case TOK_NUM:
                        printf("TOK_NUM: %s (%lf)\n", num, strtod(num, NULL)); 
                        break;
                case TOK_MULT:
                        printf("TOK_MULT\n");
                        break;    
                case TOK_DIV:
                        printf("TOK_DIV\n");
                        break;
                case TOK_ADD:
                        printf("TOK_ADD\n");
                        break;
                case TOK_SUB:
                        printf("TOK_SUB\n");
                        break;
                case TOK_EXP:
                        printf("TOK_EXP\n");
                        break;
                case TOK_NL:
                        printf("TOK_NL\n");
                        return TOK_NL;
                case TOK_QUIT:
                        printf("goodbye\n");
                        exit(EXIT_SUCCESS);
                case TOK_EOF:
                        printf("TOK_EOF\n");
                        exit(EXIT_SUCCESS);
                case TOK_ERR:
                        printf("TOK_ERR\n");
                        //eat the remaining characters in stdin
                        while ((c = getchar()) != '\n')
                                c++;
                        return TOK_ERR;         
                }
        }
}


int main(void)
{
        int tok = TOK_NL;
        char *prompt = "postfix> ";

        printf("Welcome to the postfix calculator\n");
        printf("Enter a postfix expression -- all expressions are converted to floating point\n");
        printf("Enter CTRL + C to quit or type \"quit\"\n");

        while (1) {
                if (tok == TOK_NL)
                        printf("%s", prompt);
                
                tok = calc();

                //an error occur?
                if (tok == TOK_ERR) {
                       fprintf(stderr, "error in postfix expression\n");
                       tok = TOK_NL; 
                }

        }

        return 0;
}

