/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 07:46:29 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/06 11:10:16 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	return_value;

	return_value = 0;
	while (*str != '\0')
	{
		return_value++;
		str++;
	}
	return (return_value);
}
