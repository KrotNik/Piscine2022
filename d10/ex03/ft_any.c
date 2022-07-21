/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:20:08 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/12 19:14:06 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f) (char*))
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		if (f(tab[i] == 1))
			return (1);
		i++;
	}
	return (0);
}
