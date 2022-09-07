/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:11:45 by jnho              #+#    #+#             */
/*   Updated: 2022/09/07 14:44:38 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	gap;
	int	*range_arr;
	int	arr_idx;

	if (min >= max)
		return (NULL);
	gap = max - min;
	range_arr = (int *)malloc(sizeof(int) * gap);
	if (!range_arr)
		return (0);
	arr_idx = 0;
	while (min < max)
	{
		range_arr[arr_idx] = min;
		min++;
		arr_idx++;
	}
	return (range_arr);
}
