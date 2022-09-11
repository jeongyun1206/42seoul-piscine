/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:31:43 by jnho              #+#    #+#             */
/*   Updated: 2022/08/27 07:51:45 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char	f_num;
	char	s_num;
	char	t_num;

	f_num = '0';
	while (f_num < '7')
	{
		s_num = f_num + 1;
		while (s_num < '9')
		{
			t_num = s_num +1;
			while (t_num <= '9')
			{
				write(1, &f_num, 1);
				write(1, &s_num, 1);
				write(1, &t_num, 1);
				write(1, ", ", 2);
				t_num++;
			}
			s_num++;
		}
	f_num++;
	}
	write(1, "789", 3);
}
