/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:52:33 by jnho              #+#    #+#             */
/*   Updated: 2022/08/31 11:59:57 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	ft_str(char *str, char *to_find, int idx_str)
{
	int	idx_find;

	idx_find = 0;
	while (to_find[idx_find])
	{
		if (str[idx_str] != to_find[idx_find])
			return (0);
		idx_find++;
		idx_str++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	idx_str;
	int	flag;

	flag = 0;
	if (to_find[0] == '\0')
		return (str);
	idx_str = 0;
	while (str[idx_str])
	{
		flag = ft_str(str, to_find, idx_str);
		if (flag)
			return (str + idx_str);
		idx_str++;
	}
	return (NULL);
}
