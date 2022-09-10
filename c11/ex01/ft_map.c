/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:32:08 by jnho              #+#    #+#             */
/*   Updated: 2022/09/08 19:33:27 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	tab_idx;

	tab_idx = 0;
	while (tab_idx < length)
	{
		f(tab[tab_idx]);
		tab_idx++;
	}
	return (tab);
}
