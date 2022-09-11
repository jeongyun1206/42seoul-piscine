/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:34:38 by jnho              #+#    #+#             */
/*   Updated: 2022/08/30 19:57:13 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char	*str)
{
	int	flag;
	int	idx;

	flag = 1;
	idx = 0;
	while (str[idx] != '\0')
	{
		if ((str[idx] >= 'a' ) && (str[idx] <= 'z') && flag)
			flag = 1;
		else if ((str[idx] >= 'A') && (str[idx] <= 'Z') && flag)
			flag = 1;
		else
			flag = 0;
		idx++;
	}
	return (flag);
}
