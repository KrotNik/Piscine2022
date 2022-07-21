/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nikitas_mess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:52:51 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/20 21:45:18 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**draw_solution(int nb, int cords[], char **map, char *head)
{
	int	i;
	int	j;

	i = cords[0];
	j = cords[1];
	while (i >= (cords[0] - nb + 1))
	{
		while (j >= (cords[1] - nb + 1))
		{
			map[i][j] = head[3];
			j--;
		}
		i--;
		j = cords[1];
	}
	return (map);
}

void	print_output(char **map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int	**solve_dat(char **map, int x, int y, char *head)
{
	int	i;
	int	j;
	int	**dp;
	int	max_square_len;
	int	cords[2];

	i = 0;
	j = 0;
	max_square_len = 0;
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
	j = 1;
	i = 1;
	while (x > i)
	{
		while (y > j)
		{
			if (map[i][j] == head[1])
			{
				dp[i][j] = ft_min(dp[i - 1][j], dp[i][j - 1], \
				dp[i - 1][j - 1]) + 1;
			}
			else
				dp[i][j] = 0;
			if (max_square_len < dp[i][j])
			{
				max_square_len = dp[i][j];
				cords[0] = i;
				cords[1] = j;
			}
			j++;
		}
		i++;
		j = 0;
	}
	draw_solution(max_square_len, cords, map, head);
	print_output(map, x);
	return (0);
}
