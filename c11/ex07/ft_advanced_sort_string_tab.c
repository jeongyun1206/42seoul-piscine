/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:35:18 by jnho              #+#    #+#             */
/*   Updated: 2022/09/11 19:37:14 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (1)
	{
		if ((s1[idx] == '\0') && (s2[idx] == '\0'))
			return (0);
		else if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		idx;
	int		not_sorted;
	char	*buff;

	not_sorted = 0;
	while (tab[not_sorted])
		not_sorted++;
	not_sorted--;
	if (not_sorted < 1)
		return ;
	while (not_sorted)
	{
		idx = 0;
		while (idx < not_sorted)
		{
			if (cmp(tab[idx], tab[idx + 1]) > 0)
			{
				buff = tab[idx];
				tab[idx] = tab[idx + 1];
				tab[idx + 1] = buff;
			}
			idx++;
		}
		not_sorted--;
	}
}