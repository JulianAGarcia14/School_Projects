#ifndef LEX_WORD_H_
#define LEX_WORD_H_

#define TOK_WORD        1
#define TOK_NL          2
#define TOK_EOF         3
#define TOK_ERR         4

int get_tok(FILE *fp, char *word, size_t max_len);

#endif

