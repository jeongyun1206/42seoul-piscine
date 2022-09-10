/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:37:17 by jnho              #+#    #+#             */
/*   Updated: 2022/09/10 10:47:31 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_col_plus(int num1, int num2);
int	ft_col_minus(int num1, int num2);
int	ft_col_div(int num1, int num2);
int	ft_col_multi(int num1, int num2);
int	ft_col_mod(int num1, int num2);

void set_cal_function(int (*f[5])(int, int))
{
	f[0] = ft_col_plus;
	f[1] = ft_col_minus;
	f[2] = ft_col_div;
	f[3] = ft_col_multi;
	f[4] = ft_col_mod;
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}
