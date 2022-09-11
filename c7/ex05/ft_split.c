/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:59:57 by jnho              #+#    #+#             */
/*   Updated: 2022/09/09 21:55:13 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_to_find(char *str, char *to_find, int str_idx)
{
	int	find_idx;

	find_idx = 0;
	while (to_find[find_idx])
	{
		if (str[str_idx] == to_find[find_idx])
			return (1);
		find_idx++;
	}
	return (0);
}

int	ft_split_cnt(char *str, char *to_find)
{
	int	str_idx;
	int	flag;
	int	split_cnt;

	split_cnt = 0;
	flag = 1;
	str_idx = -1;
	while (str[++str_idx])
	{
		if (ft_to_find(str, to_find, str_idx))
		{
			flag = 1;
			str[str_idx] = '\0';
		}
		else if (ft_to_find(str, to_find, str_idx) == 0 && flag)
		{
			flag = 0;
			split_cnt++;
		}
	}
	return (split_cnt);
}

char	*ft_cpy_str(char *str)
{
	char	*rtn_cpy_str;
	int		str_idx;

	str_idx = 0;
	while (str[str_idx])
		str_idx++;
	rtn_cpy_str = (char *)malloc(sizeof(char) * (str_idx + 1));
	if (!rtn_cpy_str)
		return (0);
	str_idx = 0;
	while (str[str_idx])
	{
		rtn_cpy_str[str_idx] = str[str_idx];
		str_idx++;
	}
	rtn_cpy_str[str_idx] = '\0';
	return (rtn_cpy_str);
}

char	*ft_malloc_split_word(char *str, int *str_idx)
{
	int		word_cnt;
	int		str_idx_plus;
	int		rtn_arr_idx;
	char	*rtn_arr;

	str_idx_plus = 0;
	word_cnt = 0;
	while (!str[*str_idx])
		(*str_idx)++;
	while (str[(*str_idx) + str_idx_plus])
	{
		word_cnt++;
		str_idx_plus++;
	}
	rtn_arr = (char *)malloc(sizeof(char) * (word_cnt + 1));
	if (!rtn_arr)
		return (0);
	rtn_arr_idx = 0;
	while (str[*str_idx])
		rtn_arr[rtn_arr_idx++] = str[(*str_idx)++];
	rtn_arr[rtn_arr_idx] = '\0';
	return (rtn_arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**rtn_split;
	char	*cpd_str;
	int		split_cnt;
	int		rtn_idx;
	int		str_idx;

	cpd_str = ft_cpy_str(str);
	if (!cpd_str || !str)
		return (0);
	split_cnt = ft_split_cnt(cpd_str, charset);
	rtn_split = (char **)malloc(sizeof(char *) * (split_cnt + 1));
	if (!rtn_split)
		return (0);
	rtn_idx = 0;
	str_idx = 0;
	while (rtn_idx < split_cnt)
	{
		rtn_split[rtn_idx] = ft_malloc_split_word(cpd_str, &str_idx);
		if (!rtn_split[rtn_idx])
			return (0);
		rtn_idx++;
	}
	rtn_split[rtn_idx] = 0;
	return (rtn_split);
}
