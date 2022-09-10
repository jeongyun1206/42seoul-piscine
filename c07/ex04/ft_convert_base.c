/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:10:06 by jnho              #+#    #+#             */
/*   Updated: 2022/09/08 11:16:28 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_base_confirm(char *base)
{
	int		base_len;
	int		base_arr_idx;
	char	base_arr[10000];

	base_len = 0;
	while (base[base_len])
	{
		base_arr_idx = 0;
		if (base[base_len] == '-' || base[base_len] == '+'
			|| base[base_len] == ' ' || (9 <= base[base_len]
				&& base[base_len] <= 13))
			return (0);
		while (base_arr_idx < base_len)
		{
			if (base_arr[base_arr_idx] == base[base_len])
				return (0);
			base_arr_idx++;
		}
		base_arr[base_len] = base[base_len];
		base_len++;
	}
	return (base_len);
}

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

int	string_in_base(char str_str_idx, char *base)
{
	int	base_idx;

	base_idx = 0;
	while (base[base_idx])
	{
		if (str_str_idx == base[base_idx])
			return (0);
		base_idx++;
	}
	return (1);
}

int	str_to_base_num(char str_str_idx, char *base)
{
	int	base_idx;

	base_idx = 0;
	while (base[base_idx])
	{
		if (str_str_idx == base[base_idx])
			return (base_idx);
		base_idx++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign_flag;
	int	str_idx;
	int	rtn_num;

	base_len = ft_base_confirm(base);
	if (base_len < 2)
		return (-1);
	str_idx = 0;
	sign_flag = ft_sign_flag(str, &str_idx);
	rtn_num = 0;
	if (string_in_base(str[str_idx], base) && str[str_idx])
		return (-1);
	while (str[str_idx])
	{
		if (string_in_base(str[str_idx], base))
			break ;
		rtn_num *= base_len;
		rtn_num += sign_flag * str_to_base_num(str[str_idx], base);
		str_idx++;
	}
	return (rtn_num);
}
