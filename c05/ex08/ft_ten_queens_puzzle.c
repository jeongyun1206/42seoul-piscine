/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:00:42 by jnho              #+#    #+#             */
/*   Updated: 2022/09/05 11:30:38 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	confirm_locate_queen(int *queen_location_arr, int row, int col)
{
	int	row_idx;
	int	col_idx;

	row_idx = 1;
	col_idx = 1;
	while (row - row_idx >= 0)
	{
		if (queen_location_arr[row - row_idx] == col)
			return (0);
		if (queen_location_arr[row - row_idx] == col - col_idx)
			return (0);
		if (queen_location_arr[row - row_idx] == col + col_idx)
			return (0);
		row_idx++;
		col_idx++;
	}
	return (1);
}

void	print_queen_location(int *queen_location_arr)
{
	int		row;
	char	tmp;

	row = 0;
	while (row < 10)
	{
		tmp = queen_location_arr[row] + '0';
		write(1, &tmp, 1);
		row++;
	}
	write(1, "\n", 1);
}

void	ft_ten_queens(int *queen_location_arr, int row, int *number_of_cases)
{
	int	col;

	if (row == 10)
	{
		print_queen_location(queen_location_arr);
		(*number_of_cases)++;
		return ;
	}
	col = 0;
	while (col <= 9)
	{
		if (confirm_locate_queen(queen_location_arr, row, col))
		{
			queen_location_arr[row] = col;
			ft_ten_queens(queen_location_arr, row + 1, number_of_cases);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queen_location_arr[10];
	int	number_of_cases;
	int	arr_idx;

	number_of_cases = 0;
	arr_idx = 0;
	while (arr_idx < 10)
		queen_location_arr[arr_idx++] = 0;
	ft_ten_queens(queen_location_arr, 0, &number_of_cases);
	return (number_of_cases);
}
