/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeboard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:27:12 by jnho              #+#    #+#             */
/*   Updated: 2022/09/04 17:04:23 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_1234(int **board);
int	ft_check_proper(int **board);

void	print_board(int **board)
{
	int		row;
	int		col;
	char	prt_tmp;

	row = 1;
	while (row < 5)
	{
		col = 1;
		while (col < 5)
		{
			prt_tmp = board[row][col] + '0';
			write(1, &prt_tmp, 1);
			if (col != 4)
				write(1, " ", 1);
			col++;
		}
		row++;
		write(1, "\n", 1);
	}
}

void	check_board_col(int *col, int *row)
{
	if (*col == 5)
	{
		*col = 1;
		*row += 1;
	}
	return ;
}

void	check_full_board(int **board)
{
	if (ft_check_proper(board))
	{
		print_board(board);
		board[0][0] = 1;
	}
	return ;
}

void	make_board(int **board, int **visited, int row, int col)
{
	int	put_num;

	if (board[0][0] || ft_check_1234(board) == 0)
		return ;
	if (row == 4 && col == 5)
	{
		check_full_board(board);
		return ;
	}
	check_board_col(&col, &row);
	put_num = 1;
	while (put_num <= 4)
	{
		if (visited[row][put_num] == 0)
		{
			visited[row][put_num] = 1;
			board[row][col] = put_num;
			make_board(board, visited, row, col + 1);
			visited[row][put_num] = 0;
			board[row][col] = 0;
		}
		put_num++;
	}
}
