/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:02:37 by jnho              #+#    #+#             */
/*   Updated: 2022/08/31 11:53:12 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char	*str)
{
	int	flag;
	int	idx;

	flag = 1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if ((str[idx] >= 'A' ) && (str[idx] <= 'Z') && flag)
			flag = 1;
		else
			flag = 0;
		idx++;
	}
	return (flag);
}
