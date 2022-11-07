/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_confirm_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:11:40 by jnho              #+#    #+#             */
/*   Updated: 2022/09/14 20:50:27 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_bsq.h"

int	confirm_row_length(char *map_initial, int *map_info_arr)
{
	int	row_cur_length;
	int	row_cnt;
	int	idx;

	idx = 0;
	while (map_initial[idx] != '\n')
		idx++;
	idx++;
	row_cnt = 0;
	while (map_initial[idx])
	{
		row_cur_length = 0;
		row_cnt++;
		while (map_initial[idx++] != '\n')
			row_cur_length++;
		if (row_cur_length != map_info_arr[1])
			return (0);
	}
	if (row_cnt != map_info_arr[0])
		return (0);
	return (1);
}

int	confirm_valid_character(char *map_initial, int *map_info_arr)
{
	int	idx;

	idx = 0;
	while (map_initial[idx] != '\n')
		idx++;
	idx++;
	while (map_initial[idx])
	{
		if (map_initial[idx] != '\n' && map_initial[idx] != map_info_arr[2]
			&& map_initial[idx] != map_info_arr[3])
			return (0);
		idx++;
	}
	return (1);
}

int	get_confirm_map(char *map_initial, int *map_info_arr)
{
	if (!confirm_row_length(map_initial, map_info_arr))
		return (0);
	if (!confirm_valid_character(map_initial, map_info_arr))
		return (0);
	return (1);
}
