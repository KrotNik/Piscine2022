/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:49:11 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/06 10:15:21 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_atoi(char *str)
{	
	int result;
	int sign;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign  *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while((*str >= '0') && (*str <= '9'))
	{
		result = result * 10  + (*str - 48);
		str++;
	}
	return (result * sign);
}

int main(void)
{	
	char str1[] = "123";
	int answer = ft_atoi(str1);
	printf("%i", answer);
	return(0);
}
