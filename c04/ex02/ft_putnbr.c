/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:27:13 by jnho              #+#    #+#             */
/*   Updated: 2022/08/31 11:38:02 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_nbr(int nb)
{
	int	int_arr[100];
	int	idx;

	idx = 0;
	while (nb)
	{
		int_arr[idx] = nb % 10 + '0';
		nb /= 10;
		idx++;
	}
	while (int_arr[idx - 1])
	{
		write(1, int_arr + idx - 1, 1);
		idx--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_nbr(nb);
}
