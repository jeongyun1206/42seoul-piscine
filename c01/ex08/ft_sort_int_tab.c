/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 10:27:53 by jnho              #+#    #+#             */
/*   Updated: 2022/08/28 11:26:33 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx;
	int	not_sorted;
	int	buff;

	not_sorted = size - 1;
	if (not_sorted < 0)
	{
		return ;
	}
	while (not_sorted)
	{
		idx = 0;
		while (idx < not_sorted)
		{
			buff = tab[idx];
			if (tab[idx] > tab[idx + 1])
			{
				buff = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = buff;
			}
			idx++;
		}
		not_sorted--;
	}
}
