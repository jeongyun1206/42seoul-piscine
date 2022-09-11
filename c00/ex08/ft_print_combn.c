/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:55:35 by jnho              #+#    #+#             */
/*   Updated: 2022/08/28 16:55:00 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_buff(int *num_buff, int limit, int is_last)
{
	int	idx;
	int	prt_num;

	idx = 0;
	while (idx < limit)
	{
		prt_num = num_buff[idx] + '0';
		write(1, &prt_num, 1);
		idx++;
	}
	if (is_last)
		return ;
	else
		write(1, ", ", 2);
}

void	combination(int *num_buff, int limit, int idx, int push_num)
{
	int	plus_num;

	if ((idx == limit) && (num_buff[0] == 10 - limit))
	{
		ft_print_buff(num_buff, limit, 1);
		return ;
	}
	else if (idx == limit)
	{
		ft_print_buff(num_buff, limit, 0);
		return ;
	}
	if ((num_buff[idx - 1] == 10 - limit + idx - 1) && (idx > 0))
	{
		num_buff[idx] = push_num;
		combination(num_buff, limit, idx + 1, push_num + 1);
		return ;
	}
	plus_num = 0;
	while (push_num + plus_num <= 10 - limit + idx)
	{
		num_buff[idx] = push_num + plus_num;
		combination(num_buff, limit, idx + 1, push_num + plus_num + 1);
		plus_num++;
	}
}

void	ft_print_combn(int n)
{
	int	num_buff[10];

	combination(num_buff, n, 0, 0);
}
