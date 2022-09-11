/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:22:15 by jnho              #+#    #+#             */
/*   Updated: 2022/09/10 13:52:47 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	cnt_strs_len(char **strs, int size)
{
	int	strs_len;
	int	size_idx;
	int	str_idx;

	strs_len = 0;
	size_idx = 0;
	while (size_idx < size)
	{
		str_idx = 0;
		while (strs[size_idx][str_idx])
		{
			strs_len++;
			str_idx++;
		}
		size_idx++;
	}
	return (strs_len);
}

void	fill_rtn_str(int size, char **strs, char *sep, char *rtn_str)
{
	int	size_idx;
	int	str_idx;
	int	sep_idx;
	int	rtn_str_idx;

	rtn_str_idx = 0;
	size_idx = 0;
	while (size_idx < size)
	{
		str_idx = 0;
		while (strs[size_idx][str_idx])
		{
			rtn_str[rtn_str_idx] = strs[size_idx][str_idx];
			rtn_str_idx++;
			str_idx++;
		}
		sep_idx = 0;
		while (sep[sep_idx] && size_idx != size - 1)
		{
			rtn_str[rtn_str_idx] = sep[sep_idx];
			rtn_str_idx++;
			sep_idx++;
		}
		size_idx++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*rtn_str;
	int		sep_len;
	int		total_len;

	if (size == 0)
	{
		rtn_str = (char *)malloc(sizeof(char));
		if (!rtn_str)
			return (0);
		rtn_str[0] = '\0';
		return (rtn_str);
	}
	total_len = cnt_strs_len(strs, size);
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	total_len += sep_len * (size - 1);
	rtn_str = (char *)malloc(sizeof(char) * total_len + 1);
	if (!rtn_str)
		return (0);
	fill_rtn_str(size, strs, sep, rtn_str);
	rtn_str[total_len] = '\0';
	return (rtn_str);
}
