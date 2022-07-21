/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:50:57 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/11 00:54:46 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nb); 
int **grid_maker(char **argv);
void draw_grid(int **grid);
int solve_grid(int **grid, int row, int col);

int is_safe(int **grid, int row, int col, int num)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[row][i] == num)
			return (0);
		if (grid[i][col] == num)
			return (0);
		if (grid[row + (i % 3)][col + (i / 3)] == num)
			return (0);
		i++;
	}
	return (1);
}

int put_number(int **grid, int row, int col, int i)
{
	while (i < 9)
	{
		if(is_safe(grid, row, col, i + 1))
		{
			grid[row][col] = (i + 1);
			if ((col + 1) < 9)
			{
				if (solve_grid(grid, row, col + 1))
					return (1);
				else
					grid[row][col] = 0;
			}
			else if ((row + 1) < 9)
			{
				if (solve_grid(grid, row + 1, 0))
					return(1);
				else
					grid[row][col] = 0;
			}
			else
				return(1);	
		}
		i++;
	}
	return(0);
}

int solve_grid(int **grid, int row, int col)
{
	if (row > 9 && col > 9)
		return(1);
	if (grid[row][col] != 0)
	{
		if ((col + 1) < 9)
			return(solve_grid(grid, row, col +1));
		else if ((row + 1) < 9)
			return(solve_grid(grid, row + 1, 0));
		else
			return (1);
	} 
	else
		put_number(grid, row, col, 0);
	return(0);
}

int main(int argc, char **argv)
{
	int **grid;

	if (argc != 10)
	{
		write(1, "Error!\n", 7);
		return(0);
	}
	grid = grid_maker(argv);
	if (solve_grid(grid, 0, 0))
	{
		draw_grid(grid);
	}
	else
	{
		write(1, "Error!\n", 7);
	}
	return(0);
}
