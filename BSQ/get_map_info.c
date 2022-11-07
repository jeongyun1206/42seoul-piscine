/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujinkim <yujinkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:33:18 by yujinkim          #+#    #+#             */
/*   Updated: 2022/09/14 22:07:51 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_bsq.h"

int	check_first_row(char *initial)
{
	int	i;

	i = 0;
	if (!(('0' <= initial[i]) && (initial[i] <= '9')))
		return (0);
	while (('0' <= initial[i]) && (initial[i] <= '9') && initial[i + 3] != '\n')
		i++;
	if (initial[i] == '\n' || initial[i + 1] == '\n' || initial[i + 2] == '\n')
		return (0);
	if (initial[i + 3] != '\n')
		return (0);
	if (initial[i] == initial[i + 1] || initial[i] == initial[i + 2]
		|| initial[i + 1] == initial[i + 2])
		return (0);
	return (1);
}

int	get_map_info(char *initial, int *info, int *total_len)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while ((('0' <= initial[i]) && (initial[i] <= '9'))
		&& initial[i + 3] != '\n')
	{
		result = result * 10;
		result = result + (initial[i] - '0');
		i++;
	}
	info[0] = result;
	if (info[0] != 0)
		info[1] = (*total_len - i - 4) / info[0] - 1;
	info[2] = initial[i];
	info[3] = initial[i + 1];
	info[4] = initial[i + 2];
	if (!(32 <= info[2] && info[2] <= 126)
		|| !(32 <= info[3] && info[3] <= 126)
		|| !(32 <= info[4] && info[4] <= 126) || info[0] == 0)
		return (0);
	if (!check_first_row(initial))
		return (0);
	return (1);
}
