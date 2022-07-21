/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_build_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 23:04:10 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/10 23:12:34 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> 
#include <unistd.h>
void ft_putchar(char c);
void ft_putnbr(int nb);

void draw_grid(int **grid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		while (j < 8)
		{
			ft_putnbr((grid[i][j]));
			ft_putchar(' ');
			j++;
		}
		ft_putnbr(grid[i][j]);
		ft_putchar('\n');
		j = 0;
		i++;
	}
}

int	**ft_error(void)
{
	write(1, "Error!\n", 7);
	return (0);
}

int	**grid_maker(char **argv)
{
	int	**grid;
	int	i;
	int	j;

	i = 1;
	j = 0;
	grid = (int **) malloc (sizeof (int *) * 9);
	while (i < 10)
	{
		grid[i - 1] = (int *)malloc(sizeof (int) * 9);
		while (j < 8)
		{
			if (argv[i][j] == 0)
				return (ft_error());
			if ((argv[i][j] - '0') < 0)
				grid[i - 1][j] = 0;
			else
				grid[i - 1][j] = (argv[i][j] - '0');
			j++;
		}
		j = 0;
		i++;
	}
	return (grid);
}


/*
int **grid_maker(char **array)
{
    int i;
    int j;
    int z;
   	int **grid;

    i = 0;
    grid = (int**) malloc (sizeof(int*) * 9);
    while (i < 9)
    {
        grid[i] = (int*) malloc (sizeof(int) * 9);
        i++;
    }
    i = 1;
    j = 0;
    z = 0;
    while (i < 9)
    {
        while(j < 8)
        {
			if (array[i][j] == '.')
			{
				grid[z][j] = 0;
				j++;
				z++;
			}
			else
			{
				char c  = array[i][j];
				grid[z][j] = c - '0';
            	j++;
            	z++;
			}
        }
        i++;
        z = 0;
        j = 0;
    }
    return (grid);
}
*/