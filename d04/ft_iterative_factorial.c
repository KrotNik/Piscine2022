/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:55:50 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/04 01:16:16 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	nbc;
	int	i;
	int	nbc2;

	i = 1;
	nbc = nb;
	if (nbc > 0)
	{
		while (i != nb)
		{	
			nbc2 = nb - i;
			nbc = nbc * nbc2;
			i++;
		}
		printf("%i", nbc);
		return (nbc);
	}
}

int	main(void)
{
	ft_iterative_factorial(5);
	return (0);
}
