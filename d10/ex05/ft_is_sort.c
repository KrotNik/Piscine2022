/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 21:37:49 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/12 22:32:32 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	acsending_order(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i], tab[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	desennding_order(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 1 < length)
	{
		if (f(tab[i + 1], tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (tab[1] < tab[2])
		return (acsending_order(tab, length, f));
	if (tab[1] < tab[2])
		return (acsending_order(tab, length, f));
}
