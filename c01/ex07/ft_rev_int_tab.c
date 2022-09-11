/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:24:20 by jnho              #+#    #+#             */
/*   Updated: 2022/08/28 11:28:21 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	idx;
	int	not_reversed;
	int	buff;

	not_reversed = size - 1;
	if (not_reversed < 0)
	{
		return ;
	}
	while (not_reversed)
	{
		idx = 0;
		while (idx < not_reversed)
		{
			buff = tab[idx];
			tab[idx] = tab[idx + 1];
			tab[idx + 1] = buff;
			idx++;
		}
		not_reversed--;
	}
}
