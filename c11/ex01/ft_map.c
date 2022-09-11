/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:32:08 by jnho              #+#    #+#             */
/*   Updated: 2022/09/11 19:14:32 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	tab_idx;
	int	*rtn_arr;

	rtn_arr = (int *)malloc(sizeof(int) * length);
	tab_idx = 0;
	while (tab_idx < length)
	{
		rtn_arr[tab_idx] = f(tab[tab_idx]);
		tab_idx++;
	}
	return (rtn_arr);
}
