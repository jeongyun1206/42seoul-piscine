/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:54:35 by jnho              #+#    #+#             */
/*   Updated: 2022/08/30 19:59:36 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char	*str)
{
	int	flag;
	int	idx;

	flag = 1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if ((str[idx] >= '0' ) && (str[idx] <= '9') && flag)
			flag = 1;
		else
			flag = 0;
		idx++;
	}
	return (flag);
}