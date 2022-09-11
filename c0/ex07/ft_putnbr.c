/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:00:37 by jnho              #+#    #+#             */
/*   Updated: 2022/08/28 15:36:30 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_prt_int(char *num_arr, int nb)
{
	int	idx;

	idx = 0;
	while (nb)
	{
		num_arr[idx] = nb % 10 + '0';
		nb /= 10;
		idx ++;
	}
	while (idx)
	{
		idx--;
		write(1, num_arr + idx, 1);
	}
}

void	ft_putnbr(int nb)
{
	char	num_arr[10];

	if (nb <= -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_prt_int(num_arr, nb);
}
