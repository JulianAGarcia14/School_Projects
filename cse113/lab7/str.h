/**
 * @file str.h
 *
 * @author Julian Garcia
 *
 * @date 11/4/2018
 *
 * Assignment: Lab 7
 *
 * @brief Header file or test.c
 *
 * @details Contains function declarations for test.c
 *
 * @bugs
 *
 * @todo none
 */


#ifndef STR_H_
#define STR_H

void squeeze(char s[], int c);
void psqueeze(char *s, int c);
void str_cat(char s[], char t[]);
void pstr_cat(char *s, char *t);
void pstr_ncpy(char *dest, char *src, int n);
int str_len(char *s);
int pstr_ncmp(char *s, char *t, int n);
void cswap(char *c, char *d);
void preverse(char *s);
char *pindex(char *s, int c);
#endif
