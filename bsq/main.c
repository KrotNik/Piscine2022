/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:38:58 by analves           #+#    #+#             */
/*   Updated: 2022/07/20 22:05:22 by analves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "header.h"

int get_lenght(char *str);
int how_deep(char *str);
int	**solve_dat(char **map, int x, int y, char *head);

char    **tabify(char *map);
int	main()
{
	int input;
	int i;
	char *map;
	char **tab;
	char buf;
	int	fd;
	int a = 0;
	int x;
	int y;
	char array[6];
	int k = 0;

	i = 0;
	input = open("map4", O_RDONLY);
	if (input == -1)
		printf("error \n");
	close (input);
	map = malloc(sizeof(char)*999);
	fd = open ("map4", O_RDONLY);
	while (read(fd, &buf, 1))
	{
		map[i] = buf;
		i++;
	}

	while(k < 6)
	{
		array[k] = map[k];
		k++;
	}

	map[i] = '\0';
	close(fd);
	tab = tabify(map);
	x = get_lenght(map);
	y = how_deep(map);
	print_output(tab, x);
	solve_dat(tab, x, y, array);
	return (0);
}
