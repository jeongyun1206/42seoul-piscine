/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <jnho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:39:58 by jnho              #+#    #+#             */
/*   Updated: 2022/08/28 15:36:13 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int num, int flag)
{
	int	demical;
	int	digit;

	demical = num / 10 + '0';
	digit = num % 10 + '0';
	write(1, &demical, 1);
	write(1, &digit, 1);
	if (flag == 0)
	{
		write(1, " ", 1);
	}
	if (flag == 1)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	f_num;
	int	b_num;

	f_num = 0;
	while (f_num < 98)
	{
		b_num = f_num + 1;
		while (b_num < 100)
		{
			ft_print_num(f_num, 0);
			ft_print_num(b_num, 1);
			b_num++;
		}
		f_num++;
	}
	ft_print_num(f_num, 0);
	ft_print_num(99, 2);
}
