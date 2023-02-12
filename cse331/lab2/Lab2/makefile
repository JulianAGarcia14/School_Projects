# Makefile
#
# Author: Mike Swift <theycallmeswift@gmail.com>
#
# Created on: April 28th, 2011
# Modified on: April 28th, 2011
#
# Complile using "make" and clean using "make clean"

CC = gcc
CCFLAGS  = -ansi -pedantic -Wall -g

all: sim

sim: cachesim.c cachesim.h
	$(CC) $(CCFLAGS) -o cachesim cachesim.c

	rm -rf *.o
