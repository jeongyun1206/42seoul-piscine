/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:44:14 by jnho              #+#    #+#             */
/*   Updated: 2022/09/09 19:31:56 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		src_len;
	int		cpy_idx;

	if (!src)
		return (NULL);
	src_len = 0;
	while (src[src_len])
		src_len++;
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (NULL);
	cpy_idx = 0;
	while (src[cpy_idx])
	{
		dest[cpy_idx] = src[cpy_idx];
		cpy_idx++;
	}
	dest[cpy_idx] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					idx;
	struct s_stock_str	*stock_arr;

	stock_arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_arr)
		return (0);
	idx = 0;
	while (idx < ac)
	{
		stock_arr[idx].size = ft_strlen(av[idx]);
		stock_arr[idx].str = av[idx];
		stock_arr[idx].copy = ft_strdup(av[idx]);
		idx++;
	}
	stock_arr[idx].str = 0;
	return (stock_arr);
}
