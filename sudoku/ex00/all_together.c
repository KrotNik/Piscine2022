#include <unistd.h>
#include <stdlib.h> 
#include <stdio.h> 
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	main_loop(long nb2, int devisor, int result)
{
	int	for_print;
	int	remainder;
	int	print;

	while (result == 0)
	{
		result = nb2 / devisor;
		if (result == 0)
		{
			devisor = devisor / 10;
		}
	}
	for_print = nb2 / devisor;
	ft_putchar(for_print + 48);
	remainder = nb2 % devisor;
	while (devisor != 10)
	{
		devisor = devisor / 10;
		print = remainder / devisor;
		ft_putchar(print + 48);
		remainder = remainder % devisor;
	}
	ft_putchar(remainder + 48);
}

void	ft_putnbr(int nb)
{
	long	nb2;
	int		devisor;
	int		result;
	int		return_value;

	devisor = 1000000000;
	nb2 = (long)nb;
	result = 0;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = nb2 * -1;
	}
	if (nb2 <= 9)
	{
		return_value = nb2 + 48;
		ft_putchar(return_value);
	}
	else
	{
		main_loop(nb2, devisor, result);
	}
}

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
	int debug[9][9];

	i = 1;
	j = 0;
	grid = (int **) malloc (sizeof (int *) * 9);
	while (i < 10)
	{
		grid[i - 1] = (int *)malloc(sizeof (int) * 9);
		while (j < 9)
		{
			if (argv[i][j] == 0)
				return (ft_error());
			if ((argv[i][j] - '0') < 0)
			{
				grid[i - 1][j] = 0;
				debug[i - 1][j] = grid[i - 1][j];
			}
			else
			{
				grid[i - 1][j] = (argv[i][j] - '0');
				debug[i - 1][j] = grid[i - 1][j];
			}
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
	int debug[9][9];
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
			if (array[i][j] == '\0')
				return(0);
			if (array[i][j] == '.')
			{
				grid[z][j] = 0;
				debug[z][j] = grid[z][j];
				j++;
				z++;
			}
			else
			{
				char c  = array[i][j];
				grid[z][j] = c - '0';
				debug[z][j] = grid[z][j];
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


int solve_grid(int **grid, int row, int col);


/*
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
*/

int is_safe(int **grid, int row, int col, int num)
{
	int row_start = row / 3 * 3;
	int col_start = col / 3 * 3;
	int	i;

	i = 0;
	while (i < 9)
	{
		if (grid[row][i] == num)
			return (0);
		if (grid[i][col] == num)
			return (0);
		if (grid[row_start + (i % 3)][col_start + (i / 3)] == num)
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
		return put_number(grid, row, col, 0);
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
		draw_grid(grid);
		write(1, "Error!\n", 7);
		return(0);
	}
	return(0);
}
