/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:43:22 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/07 15:04:28 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{	
	char	*target;
	int		l;
	int		i;

	l = 0;
	i = 0;
	while (src[l] != '\0')
	{
		l++;
	}
	l++;
	target = (char *) malloc (sizeof (char) * l);
	while (i != l)
	{
		target[i] = src[i];
		i++;
	}
	return (target);
}
