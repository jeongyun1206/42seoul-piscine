/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:29:08 by jnho              #+#    #+#             */
/*   Updated: 2022/09/11 15:38:24 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_doop.h"

int	ft_col_plus(int num1, int num2)
{
	int	rtn_num;

	rtn_num = num1 + num2;
	ft_putnbr(rtn_num);
	return (rtn_num);
}

int	ft_col_minus(int num1, int num2)
{
	int	rtn_num;

	rtn_num = num1 - num2;
	ft_putnbr(rtn_num);
	return (rtn_num);
}

int	ft_col_div(int num1, int num2)
{
	int	rtn_num;

	if (num2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	rtn_num = num1 / num2;
	ft_putnbr(rtn_num);
	return (rtn_num);
}

int	ft_col_multi(int num1, int num2)
{
	int	rtn_num;

	rtn_num = num1 * num2;
	ft_putnbr(rtn_num);
	return (rtn_num);
}

int	ft_col_mod(int num1, int num2)
{
	int	rtn_num;

	if (num2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	rtn_num = num1 % num2;
	ft_putnbr(rtn_num);
	return (rtn_num);
}
