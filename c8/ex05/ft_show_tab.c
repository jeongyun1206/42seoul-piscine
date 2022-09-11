/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:14:50 by jnho              #+#    #+#             */
/*   Updated: 2022/09/08 21:16:22 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_stock_str.h"
#include<unistd.h>

void	ft_putstr(char	*str)
{
	int	idx;

	idx = 0;
	while (str [idx])
	{
		write(1, str + idx, 1);
		idx++;
	}
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int	par_idx;

	par_idx = 0;
	while (par[par_idx].str)
	{
		ft_putstr(par[par_idx].str);
		write(1, "\n", 1);
		ft_putnbr(par[par_idx].size);
		write(1, "\n", 1);
		ft_putstr(par[par_idx].copy);
		write(1, "\n", 1);
		par_idx++;
	}
}
