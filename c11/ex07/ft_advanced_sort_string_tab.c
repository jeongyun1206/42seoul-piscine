/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:35:18 by jnho              #+#    #+#             */
/*   Updated: 2022/09/09 19:48:08 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		tab_idx;
	int		tab_len;
	char	*tmp;

	tab_len = 0;
	while (tab[tab_len])
		tab_len++;
	while (tab_len - 1)
	{
		while (tab_idx < tab_len - 1)
		{
			if (cmp(tab[tab_idx], tab[tab_idx + 1]))
			{
				tmp = tab[tab_idx];
				tab[tab_idx] = tab[tab_idx + 1];
				tab[tab_idx + 1] = tmp;
			}
			tab_idx++;
		}
		tab_len--;
	}
}
