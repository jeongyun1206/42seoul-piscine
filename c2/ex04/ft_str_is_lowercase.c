/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:56:31 by jnho              #+#    #+#             */
/*   Updated: 2022/08/31 11:52:04 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char	*str)
{
	int	flag;
	int	idx;

	flag = 1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if ((str[idx] >= 'a' ) && (str[idx] <= 'z') && flag)
			flag = 1;
		else
			flag = 0;
		idx++;
	}
	return (flag);
}
