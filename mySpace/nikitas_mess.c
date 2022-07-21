#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
//from here functions that have actually been written for bsq

//finds smallest vallue from the passed vallues
int	ft_min(int a, int b, int c)
{
	int small;

	small = a;
	if (small > b)
		small = b;
	if (small > c)
		small = c;
	return (small);
}

//edits the map arary, (adds x)
char	**draw_solution(int nb, int cords[], char **map, char *head)
{
	int i = cords[0];
	int j = cords[1];

	while (i >= (cords[0] - nb + 1))
	{
		while(j >= (cords[1] - nb + 1))
		{
			map[i][j] = head[3];
			j--;
		}
		i--;
		j = cords[1];
	}
	return(map);
}

//prints the final output to the console
void print_output (char **map, int x)
{
	int i = 0;
	while (i < x)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
//solves dat thing!
int	**solve_dat(char **map, int x, int y, char *head)
{
	int i = 0;
	int j = 0;
	int **dp;
	int maxSquareLen = 0;
	int cord_x;
	int cord_y;
	int cords[2];

	dp = (int **) malloc (sizeof (int *) * x);
	while (i < x)
	{
		dp[i] = (int *) malloc (sizeof (int *) * y);
		while (j < y)
		{
			dp[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	i = 0;
	j = 0;

	//setup for the stuff!
	while (j < y)
	{
		if (map[0][j] == head[1])
			dp[0][j] = 1;
		else
			dp[0][j] = 0;
		j++;
	}
	while (i < x)
	{
		if (map[i][0] == head[1])
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
		i++;
	}
	//main shit happens here!
	j = 1;
	i = 1;
	while (x > i)
	{
		while (y > j)
		{
			if (map[i][j] == head[1])
				dp[i][j] = ft_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
			else
				dp[i][j] = 0;
			if (maxSquareLen < dp[i][j])
				{
					maxSquareLen = dp[i][j];
					cords[0] = i;
					cords[1] = j;
				}
			j++;
		}
		i++;
		j = 0;
	}
	//calls functions draw and print, to print output LOL!
	draw_solution(maxSquareLen, cords, map, head);
	print_output(map, x);
	return(dp);
}

int	main(void)
{
	//this whole shit is just setting up the test stuff, that should be passed from the file in real
	char **map_test2;
	int i = 0;
	int j = 0;

	map_test2 = (char **) malloc (sizeof (char *) * 9);
	while (i < 9)
	{
		map_test2[i] = (char *) malloc (sizeof (char) * 27);
		while (j < 27)
		{
			map_test2[i][j] = '.';
			j++;
		}
		map_test2[i][j] = '\0';
		j = 0;
		i++;
	}
	map_test2[1][4] = 'o';
	map_test2[2][12] = 'o';
	map_test2[4][4] = 'o';
	map_test2[5][15] = 'o';
	map_test2[7][6] = 'o';
	map_test2[7][21] = 'o';
	map_test2[8][2] = 'o';
	map_test2[8][10] = 'o';


	int x = 9;
	int y = 27;
	char head[5] = "4.ox";
	solve_dat(map_test2, x, y, head);
	return (0);
}
