/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:18:53 by jnho              #+#    #+#             */
/*   Updated: 2022/09/07 17:27:54 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	*function_range(int min, int max)
{
	int	gap;
	int	*range_arr;
	int	arr_idx;

	if (min >= max)
		return (0);
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

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else if (!function_range(min, max))
	{
		return (-1);
	}
	else
	{
		*range = function_range(min, max);
		return (max - min);
	}
}
