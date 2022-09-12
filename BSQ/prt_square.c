/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:50:45 by jnho              #+#    #+#             */
/*   Updated: 2022/09/12 20:57:01 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	find_biggest_square(int **dp_map, int *biggest_info_arr, int *map_info_arr)
{
	int	row_idx;
	int	col_idx;
	int	biggest_size;

	biggest_size = 0;
	row_idx = 0;
	while (row_idx < map_info_arr[0])
	{
		col_idx = 0;
		while (col_idx < map_info_arr[1])
		{
			if (biggest_size < dp_map[row_idx][col_idx])
			{
				biggest_size = dp_map[row_idx][col_idx];
				biggest_info_arr[0] = row_idx;
				biggest_info_arr[1] = col_idx;
			}
			col_idx++;
		}
		row_idx++;
	}
	biggest_info_arr[2] = biggest_size;
}

void	fill_biggest_square(char **map, int *biggest_info_arr, int *map_info_arr)
{
	int	row_idx;
	int	col_idx;
	int	sqr_col;
	int	sqr_row;

	sqr_row = biggest_info_arr[0];
	sqr_col = biggest_info_arr[1];
	row_idx = 0;
	while (row_idx < biggest_info_arr[2])
	{
		col_idx = 0;
		while (col_idx < biggest_info_arr[2])
		{
			map[sqr_row - row_idx][sqr_col - col_idx] = map_info_arr[4];
			col_idx++;
		}
		row_idx++;
	}
}

void	prt_map(char **map, int *map_info_arr)
{
	int	row_idx;
	int	col_idx;

	row_idx = 0;
	while (row_idx < map_info_arr[0])
	{
		col_idx = 0;
		while (col_idx < map_info_arr[1])
		{
			write(1, &map[row_idx][col_idx], 1);
			col_idx++;
		}
		row_idx++;
		write(1, "\n", 1);
	}
}

void	prt_biggest_square(char **map, int **dp_map, int *map_info_arr)
{
	int	biggest_info_arr[3];

	find_biggest_square(dp_map, biggest_info_arr, map_info_arr);
	if (biggest_info_arr[2] == 0)
	{
		write(1, "map_error\n", 10);
		return ;
	}
	fill_biggest_square(map, biggest_info_arr, map_info_arr);
	prt_map(map, map_info_arr);
}
