/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_fuction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:29:08 by jnho              #+#    #+#             */
/*   Updated: 2022/09/09 20:13:20 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_put_nbr(int nb);

int	ft_col_plus(int num1, int num2)
{
	int	rtn_num;

	rtn_num = num1 + num2;
	ft_put_nbr(rtn_num);
	return (rtn_num);
}

int	ft_col_minus(int num1, int num2)
{
	int	rtn_num;

	rtn_num = num1 - num2;
	ft_put_nbr(rtn_num);
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
	ft_put_nbr(rtn_num);
	return (rtn_num);
}

int	ft_col_multi(int num1, int num2)
{
	int	rtn_num;

	rtn_num = num1 * num2;
	ft_put_nbr(rtn_num);
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
	ft_put_num(rtn_num);
	return (rtn_num);
}
