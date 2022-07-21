/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:48:19 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/07 21:52:01 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*array;
	int	i;
	long min1;
	long max1;

	if (min >= max:)
		return (NULL);
	min1 = min;
	max1 = max;
	range = max - min;
	array = (int *) malloc (sizeof (int) * range);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i != range)
	{
		array[i] = (min + i);
		i++;
	}
	return (array);
}
