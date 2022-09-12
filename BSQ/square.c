/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:10:37 by jnho              #+#    #+#             */
/*   Updated: 2022/09/12 20:57:51 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	prt_biggest_square(char **map, int **dp_map, int *map_info_arr);

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

	row_idx = 0;
	dp_map = (int **)malloc(sizeof(int *) * map_info_arr[0]);
	if (!dp_map)
		return (0);
	while (row_idx < map_info_arr[0])
	{
		dp_map[row_idx] = (int *)malloc(sizeof(int) * map_info_arr[1]);
		if (!dp_map[row_idx])
			return (0);
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
				dp_map[row_idx][col_idx] = 0;
			else
				dp_map[row_idx][col_idx] = 1;
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
	fill_dp_map(dp_map, map_info_arr);
	prt_biggest_square(map, dp_map, map_info_arr);
}

/**
#include<string.h>
int main(void)
{
	int map_info_arr[5];
	map_info_arr[0] = 9;
	map_info_arr[1] = 27;
	map_info_arr[2] = 'o';
	map_info_arr[3] = '.';
	map_info_arr[4] = 'X';

	char **map = (char **)malloc(sizeof(char *) * 9);
	for (int i = 0; i < 9; i++)
	{
		map[i] = (char *)malloc(sizeof(char) * 28);
	}
	strcpy(map[0], "...........................");
	strcpy(map[1], "....o......................");
	strcpy(map[2], "............o..............");
	strcpy(map[3], "...........................");
	strcpy(map[4], "....o......................");
	strcpy(map[5], "...............o...........");
	strcpy(map[6], "...........................");
	strcpy(map[7], "......o..............o.....");
	strcpy(map[8], "..o.......o................");

	square(map, map_info_arr);
}**/
