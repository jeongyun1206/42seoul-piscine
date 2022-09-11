/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:37:57 by jnho              #+#    #+#             */
/*   Updated: 2022/09/11 19:29:39 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_up(int *tab, int length, int (*f)(int, int))
{
	int	idx;

	idx = 0;
	while (idx < length - 1)
	{
		if (f(tab[idx], tab[idx + 1]) < 0)
			return (0);
		idx++;
	}
	return (1);
}

int	check_down(int *tab, int length, int (*f)(int, int))
{
	int	idx;

	idx = 0;
	while (idx < length - 1)
	{
		if (f(tab[idx], tab[idx + 1]) > 0)
			return (0);
		idx++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	down;
	int	up;

	down = check_down(tab, length, f);
	up = check_up(tab, length, f);
	if (down || up)
		return (1);
	else
		return (0);
}
