/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:37:46 by jnho              #+#    #+#             */
/*   Updated: 2022/09/11 15:37:47 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOP_H
# define FT_DOOP_H

int		ft_col_plus(int num1, int num2);
int		ft_col_minus(int num1, int num2);
int		ft_col_div(int num1, int num2);
int		ft_col_multi(int num1, int num2);
int		ft_col_mod(int num1, int num2);
void	ft_prt_int(char *num_arr, int nb);
void	ft_putnbr(int nb);
int		ft_sign_flag(char *str, int *str_idx);
int		ft_atoi(char *str);
void	set_cal_function(int (*f[5])(int, int));
int		ft_strlen(char *str);

#endif
