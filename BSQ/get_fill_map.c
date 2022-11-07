/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fill_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:22:12 by jnho              #+#    #+#             */
/*   Updated: 2022/09/14 20:18:20 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_bsq.h"

char	**malloc_map(int *map_info_arr)
{
	int		row_idx;
	int		free_idx;
	char	**map;

	map = (char **)malloc(sizeof(char *) * map_info_arr[0]);
	if (!map)
		return (0);
	row_idx = 0;
	while (row_idx < map_info_arr[0])
	{
		map[row_idx] = (char *)malloc(sizeof(char) * map_info_arr[1]);
		if (!map[row_idx])
		{
			free_idx = 0;
			while (free_idx < row_idx)
				free(map[free_idx++]);
			free(map);
			return (0);
		}
		row_idx++;
	}
	return (map);
}

char	**get_fill_map(char *map_initial, int *map_info_arr)
{
	char	**map;
	int		row_idx;
	int		col_idx;
	int		idx;

	map = malloc_map(map_info_arr);
	if (!map)
		return (0);
	idx = 0;
	while (map_initial[idx] != '\n')
		idx++;
	idx++;
	row_idx = 0;
	while (row_idx < map_info_arr[0])
	{
		col_idx = 0;
		while (col_idx < map_info_arr[1])
			map[row_idx][col_idx++] = map_initial[idx++];
		row_idx++;
		idx++;
	}
	return (map);
}
