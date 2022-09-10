/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:37:17 by jnho              #+#    #+#             */
/*   Updated: 2022/09/10 10:22:45 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_col_plus(int num1, num2);
int	ft_col_minus(int num1, num2);
int	ft_col_div(int num1, num2);
int	ft_col_multi(int num1, num2);
int	ft_col_mod(int num1, num2);

void set_cal_function(int (*f)(int, int))
