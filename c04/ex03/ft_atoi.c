/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:27:25 by jnho              #+#    #+#             */
/*   Updated: 2022/09/05 17:06:34 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sign_flag(char *str, int *str_idx)
{
	int	minus_cnt;

	minus_cnt = 0;
	while (str[*str_idx])
	{
		if (str[*str_idx] != ' ' && !(9 <= str[*str_idx]
				&& str[*str_idx] <= 13))
			break ;
		(*str_idx)++;
	}
	while (str[*str_idx])
	{
		if (str[*str_idx] == '-')
			minus_cnt++;
		if (str[*str_idx] != '-' && str[*str_idx] != '+')
			break ;
		(*str_idx)++;
	}
	if (minus_cnt % 2)
		return (-1);
	else
		return (1);
}

int	ft_atoi(char *str)
{
	int	str_idx;
	int	rtn_num;
	int	sign_flag;

	rtn_num = 0;
	str_idx = 0;
	sign_flag = ft_sign_flag(str, &str_idx);
	while ('0' <= str[str_idx] && str[str_idx] <= '9')
	{
		rtn_num *= 10;
		rtn_num += sign_flag * (str[str_idx] - '0');
		str_idx++;
	}
	return (rtn_num);
}
