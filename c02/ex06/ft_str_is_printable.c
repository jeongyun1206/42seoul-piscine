/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:58:32 by jnho              #+#    #+#             */
/*   Updated: 2022/08/31 11:52:21 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char	*str)
{
	int	flag;
	int	idx;

	flag = 1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if ((str[idx] >= 32) && (str[idx] <= 126) && flag)
			flag = 1;
		else
			flag = 0;
		idx++;
	}
	return (flag);
}