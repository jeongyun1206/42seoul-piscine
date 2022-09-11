/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:27:42 by jnho              #+#    #+#             */
/*   Updated: 2022/09/05 18:05:32 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_nbr_to_base(long long nbr, int base_len, char *base)
{
	long long	arr[10000];
	long long	arr_idx;
	char		base_char;

	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	else if (nbr == 0)
		write(1, base, 1);
	arr_idx = 0;
	while (nbr)
	{
		arr[arr_idx] = nbr % base_len;
		nbr /= base_len;
		arr_idx++;
	}
	while (arr_idx--)
	{
		base_char = base[arr[arr_idx]];
		write(1, &base_char, 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;
	int				base_arr_idx;
	char			base_arr[1000];
	long long		nbr_l;

	nbr_l = (long long)nbr;
	base_len = 0;
	while (base[base_len])
	{
		base_arr_idx = 0;
		if (base[base_len] == '-' || base[base_len] == '+')
			return ;
		while (base_arr_idx < base_len)
		{
			if (base_arr[base_arr_idx] == base[base_len])
				return ;
			base_arr_idx++;
		}
		base_arr[base_len] = base[base_len];
		base_len++;
	}
	if (base_len <= 1)
		return ;
	ft_nbr_to_base(nbr_l, base_len, base);
}
