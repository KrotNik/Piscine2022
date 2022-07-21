#ifndef __HEADER_H__
# define __HEADER_H__
#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_min(int a, int b, int c);
char	**draw_solution(int nb, int cords[], char **map, char *head);
void	print_output(char **map, int x);
int	**solve_dat(char **map, int x, int y, char *head);

#endif
