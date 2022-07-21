/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:31:20 by analves           #+#    #+#             */
/*   Updated: 2022/07/20 21:55:41 by analves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

char	**create_memo(int x, int y)
{
	char **tab;
	int	i;

	i = 0;
	tab = (char **) malloc (sizeof(char *) * y + 1);
	if(tab == NULL)
		return (NULL);
	while (i <= x + 1)
	{
		tab[i] = (char *) malloc (sizeof(char) * x + 1);
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	return (tab);
}
void	destroy_grid(int **grid, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
int	get_lenght(char *tab)
{
	int i;
	int f;
	f = 6;
	while (tab[f] != '\n')
		f++;
	return (f - 6);
}
int how_deep(char *tab)
{
	int i;
	int counter;

	i = 0;
	counter =  0;
	while (tab[i] != '\0')
	{
		if (tab[i] == '\n')
		{
			counter++;
		}
		i++;
	}
	return (counter - 1);
}

char	**tabify(char *map) // create a 2d array
{
	char	**tab;
	int	x;
	int	y;
	int		j;
	int i;
	int a;

	a = 6;
	j = 0;
	i = 0;
	x = get_lenght(map);
	y = how_deep(map);
	tab = create_memo(x, y);
	while (map[a] != '\0')
	{
		tab[i][j] = map[a];
		if (map[a] == '\n')
		{
			j++;
			i = 0;
			a++;
		}
	i++;
	a++;
	}
	return (tab);
}
/*int	map_checker(char **map, char emp, char obs, char full)
//checks if all of them have the same length
// checks if the map only have the proper chars
{
	int i;
	int j;

	j = 1;
	i = 0;
	while (map[j][i] != '\0')
	{
		if (len_checker(map[j - 1], map[j]) == 1)
	

		return (1);
		j++;
	}
	if (char_checker(**map, emp, obs, full) == 1)
		return (1);
	return (0);
}
int	char_checker(char **map, char emp, char obs, char full)
{
	int i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == emp || map[i] == obs || map[i] == full)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
int	len_checker(char *tab1, char *tab2)
{
	int	i;
	int counter;
	int counter2;
	int j;

	counter2 = 0;
	counter = 0;
	i = 0;
	j = 0;
	while (tab1[i] !='\0')
	{
		i++;
		counter++;
	}
	while (tab2[j] != '\0')
	{
		counter2++;
		j++;
	}
	if (counter == counter2)
	{
		return (1);
	}
	return (0);
}
*/
