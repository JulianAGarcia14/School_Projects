/**
* @file life.h
*
* @author Julian Garcia
*
* @date 12/04/2018
*
* Assignment: Game of Life
*
* @brief Header file for life.c
*
*/
#ifndef LIFE_H_
#define LIFE_H_

char *get_data(char *s);
void end_prog(int err);
unsigned char **init_matrix(int rows, int cols);
int find_size(int dimension, int sprite);
void free_matrix(unsigned char **a, int rows);

#endif
