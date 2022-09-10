/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:12:26 by jnho              #+#    #+#             */
/*   Updated: 2022/09/10 15:07:25 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
void	set_cal_function(int (*f[5])(int, int));
int		ft_strlen(char *str);

void	ft_prt_int(char *num_arr, int nb)
{
	int	idx;

	idx = 0;
	while (nb)
	{
		num_arr[idx] = nb % 10 + '0';
		nb /= 10;
		idx ++;
	}
	while (idx)
	{
		idx--;
		write(1, num_arr + idx, 1);
	}
}

void	ft_putnbr(int nb)
{
	char	num_arr[10];

	if (nb <= -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	ft_prt_int(num_arr, nb);
	write(1, "\n", 1);
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

int	 main(int argc, char **argv)
{
	int	(*f[5])(int, int);
	int	rtn_num;

	set_cal_function(f);
	rtn_num = 0;
	if (argc != 4)
	{
		printf("check\n");
		write(1, "0\n", 2);
		return (0);
	}
	if (argv[2][0] == '+')
		rtn_num = f[0](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '-' && ft_strlen(argv[2]) == 1)
		rtn_num = f[1](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '/' && ft_strlen(argv[2]) == 1)
		rtn_num = f[2](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argv[2][0] == '*' && ft_strlen(argv[2]) == 1)
	{
		printf("check\n");
		rtn_num = f[3](ft_atoi(argv[1]), ft_atoi(argv[3]));
	}
	else if (argv[2][0] == '%' && ft_strlen(argv[2]) == 1)
		rtn_num = f[4](ft_atoi(argv[1]), ft_atoi(argv[3]));
	else
	{
		printf("operator_error\n");
		write(1, "0\n", 2);
	}
	return (rtn_num);
}
