/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soo-choi <soo-choi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:55:30 by soo-choi          #+#    #+#             */
/*   Updated: 2022/08/28 14:11:25 by soo-choi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_first_line(int x)
{
	int	row;

	row = 1;
	while (row <= x)
	{
		if (row == 1)
			ft_putchar('o');
		else if (row != x)
			ft_putchar('-');
		else if (row == x)
			ft_putchar('o');
		row++;
	}
}

void	ft_mid_line(int x)
{
	int	row;

	row = 1;
	while (row <= x)
	{
		if (row == 1)
			ft_putchar('|');
		else if (row != x)
			ft_putchar(' ');
		else if (row == x)
			ft_putchar('|');
		row++;
	}
}

void	ft_last_line(int x)
{
	int	row;

	row = 1;
	while (row <= x)
	{
		if (row == 1)
			ft_putchar('o');
		else if (row != x)
			ft_putchar('-');
		else if (row == x)
			ft_putchar('o');
		row++;
	}
}

void	rush(int x, int y)
{
	int	line;

	line = 1;
	while (line <= y)
	{
		if (line == 1)
			ft_first_line(x);
		else if (line != y)
			ft_mid_line(x);
		else if (line == y)
			ft_last_line(x);
		ft_putchar('\n');
		line++;
	}
}

int		main(void);
