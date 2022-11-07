/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_by_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:49:54 by jnho              #+#    #+#             */
/*   Updated: 2022/09/14 21:57:33 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_bsq.h"

int	get_map_initial_file(char *file_name, char **map_initial, int *total_len)
{
	char	buff[10];
	int		buff_size;
	int		fd;

	*total_len = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	while (1)
	{
		buff_size = read(fd, buff, 10);
		*total_len += buff_size;
		if (buff[buff_size - 1] == '\0')
			break ;
	}
	close(fd);
	*map_initial = (char *)malloc(sizeof(char) * *total_len);
	if (!*map_initial)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read(fd, *map_initial, *total_len) == -1)
		return (-1);
	return (1);
}

char	**free_map_initial(char *map_initial)
{
	free(map_initial);
	return (0);
}

char	**get_map_by_file(char *file_name, int *map_info_arr)
{
	char	**map;
	char	*map_initial;
	int		total_len;
	int		initial_rtn;

	initial_rtn = get_map_initial_file(file_name, &map_initial, &total_len);
	if (initial_rtn == 0)
		return (0);
	else if (initial_rtn == -1)
		return (free_map_initial(map_initial));
	if (!get_map_info(map_initial, map_info_arr, &total_len))
		return (free_map_initial(map_initial));
	if (!get_confirm_map(map_initial, map_info_arr))
		return (free_map_initial(map_initial));
	map = get_fill_map(map_initial, map_info_arr);
	if (!map)
		return (free_map_initial(map_initial));
	free(map_initial);
	return (map);
}
