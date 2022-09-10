/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:35:59 by jnho              #+#    #+#             */
/*   Updated: 2022/09/08 19:37:39 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	if_count_if(char **tab, int length, int (*f)(char *))
{
	int	idx;
	int	rtn_cnt;

	rtn_cnt = 0;
	idx = 0;
	while (idx < length)
	{
		if (f(tab[idx]))
			rtn_cnt++;
		idx++;
	}
	return (rtn_cnt);
}
