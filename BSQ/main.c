/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:11:40 by jnho              #+#    #+#             */
/*   Updated: 2022/09/14 21:56:37 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_bsq.h"
#include <unistd.h>
#include <fcntl.h>

int	get_map_file_by_stdin(void)
{
	char	tmp;
	int		fd;

	fd = open("map.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		return (0);
	while (read(0, &tmp, 1) > 0)
		write(fd, &tmp, 1);
	close(fd);
	return (1);
}

void	argc_one(int *map_info_arr)
{
	char	**map;

	if (!get_map_file_by_stdin())
	{
		write(2, "MAP_ERROR\n", 10);
		return ;
	}
	map = get_map_by_file("map.txt", map_info_arr);
	if (!map)
	{
		write(2, "MAP_ERROR\n", 10);
		return ;
	}
	square(map, map_info_arr);
}

int	main(int argc, char **argv)
{
	char	**map;
	int		map_info_arr[5];
	int		test_case;

	if (argc == 1)
		argc_one(map_info_arr);
	test_case = 1;
	while (test_case < argc)
	{
		map = get_map_by_file(argv[test_case], map_info_arr);
		if (!map)
		{
			write(2, "MAP_ERROR\n", 10);
			test_case++;
			continue ;
		}
		square(map, map_info_arr);
		test_case++;
	}
	return (0);
}
