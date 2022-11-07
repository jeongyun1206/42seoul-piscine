/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:10:37 by jnho              #+#    #+#             */
/*   Updated: 2022/09/14 20:17:29 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_bsq.h"

void	free_all_map(char **map, int **dp_map, int *map_info_arr);

int	dp_size(int **dp_map, int row_idx, int col_idx)
{
	int	min_num;

	if (row_idx == 0 || col_idx == 0)
		return (1);
	min_num = dp_map[row_idx - 1][col_idx];
	if (min_num > dp_map[row_idx - 1][col_idx - 1])
		min_num = dp_map[row_idx - 1][col_idx - 1];
	if (min_num > dp_map[row_idx][col_idx - 1])
		min_num = dp_map[row_idx][col_idx - 1];
	return (min_num + 1);
}

void	fill_dp_map(int **dp_map, int *map_info_arr)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < map_info_arr[0])
	{
		col_idx = 0;
		while (col_idx < map_info_arr[1])
		{
			if (dp_map[row_idx][col_idx])
				dp_map[row_idx][col_idx] = dp_size(dp_map, row_idx, col_idx);
			col_idx++;
		}
		row_idx++;
	}
}

int	**malloc_dp_map(int *map_info_arr)
{
	int	**dp_map;
	int	row_idx;
	int	free_idx;

	row_idx = 0;
	dp_map = (int **)malloc(sizeof(int *) * map_info_arr[0]);
	if (!dp_map)
		return (0);
	while (row_idx < map_info_arr[0])
	{
		dp_map[row_idx] = (int *)malloc(sizeof(int) * map_info_arr[1]);
		if (!dp_map[row_idx])
		{
			free_idx = 0;
			while (free_idx < row_idx)
				free(dp_map[free_idx++]);
			return (0);
		}
		row_idx++;
	}
	return (dp_map);
}

int	**make_dp_map(char **map, int *map_info_arr)
{
	int	**dp_map;
	int	row_idx;
	int	col_idx;

	dp_map = malloc_dp_map(map_info_arr);
	if (!dp_map)
		return (0);
	row_idx = 0;
	while (row_idx < map_info_arr[0])
	{
		col_idx = 0;
		while (col_idx < map_info_arr[1])
		{
			if (map[row_idx][col_idx] == map_info_arr[2])
				dp_map[row_idx][col_idx] = 1;
			else
				dp_map[row_idx][col_idx] = 0;
			col_idx++;
		}
		row_idx++;
	}
	return (dp_map);
}

void	square(char **map, int *map_info_arr)
{
	int	**dp_map;

	dp_map = make_dp_map(map, map_info_arr);
	if (!dp_map)
		return ;
	fill_dp_map(dp_map, map_info_arr);
	prt_biggest_square(map, dp_map, map_info_arr);
	free_all_map(map, dp_map, map_info_arr);
}
