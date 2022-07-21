/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivasile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 23:08:49 by nivasile          #+#    #+#             */
/*   Updated: 2022/07/09 18:24:44 by nivasile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	main_loop(long nb2, int devisor, int result)
{
	int	for_print;
	int	remainder;
	int	print;

	while (result == 0)
	{
		result = nb2 / devisor;
		if (result == 0)
		{
			devisor = devisor / 10;
		}
	}
	for_print = nb2 / devisor;
	ft_putchar(for_print + 48);
	remainder = nb2 % devisor;
	while (devisor != 10)
	{
		devisor = devisor / 10;
		print = remainder / devisor;
		ft_putchar(print + 48);
		remainder = remainder % devisor;
	}
	ft_putchar(remainder + 48);
}

void	ft_putnbr(int nb)
{
	long	nb2;
	int		devisor;
	int		result;
	int		return_value;

	devisor = 1000000000;
	nb2 = (long)nb;
	result = 0;
	if (nb2 < 0)
	{
		ft_putchar('-');
		nb2 = nb2 * -1;
	}
	if (nb2 <= 9)
	{
		return_value = nb2 + 48;
		ft_putchar(return_value);
	}
	else
	{
		main_loop(nb2, devisor, result);
	}
}
