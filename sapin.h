#ifndef SAPIN_H_
# define SAPIN_H_
#define KNRM  "\x1B[0m"
#define KGRN  "\x1B[32m"
#define KBRW  "\e[38;5;130m"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void    my_putchar(char c);
int     lines(int size, int line, int jump);
void	draw_branch(int nb, int size);
void	draw_trunk(int size);
void    draw_fir(int size);

#endif