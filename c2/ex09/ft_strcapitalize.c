/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:00:55 by jnho              #+#    #+#             */
/*   Updated: 2022/08/31 11:52:47 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char	*str)
{
	int	idx;
	int	flag;

	idx = 0;
	flag = 1;
	while (str[idx])
	{
		if ((flag) && (str[idx] >= 'a') && (str[idx] <= 'z'))
		{
			str[idx] += 'A' - 'a';
			flag = 0;
		}
		else if ((flag == 0) && ((str[idx] >= 'A') && (str[idx] <= 'Z')))
		{
			str[idx] -= 'A' - 'a';
		}
		if ((('a' <= str[idx]) && (str[idx] <= 'z'))
			|| (('A' <= str[idx]) && (str[idx] <= 'Z'))
			|| ('0' <= str[idx] && str[idx] <= '9'))
			flag = 0;
		else
			flag = 1;
		idx++;
	}
	return (str);
}
