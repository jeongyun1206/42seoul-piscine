/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_board_condition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:13:19 by jnho              #+#    #+#             */
/*   Updated: 2022/09/03 17:01:43 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_col_condition(int **board, char *input)
{
	int	input_idx;
	int	col_idx;

	input_idx = 0;
	col_idx = 1;
	while (col_idx < 5)
	{
		board[0][col_idx] = input[input_idx] - '0';
		input_idx += 2;
		col_idx++;
	}
	col_idx = 1;
	while (col_idx < 5)
	{
		board[5][col_idx] = input[input_idx] - '0';
		input_idx += 2;
		col_idx++;
	}
}

void	fill_row_condition(int **board, char *input)
{
	int	input_idx;
	int	row_idx;

	input_idx = 16;
	row_idx = 1;
	while (row_idx < 5)
	{
		board[row_idx][0] = input[input_idx] - '0';
		input_idx += 2;
		row_idx++;
	}
	row_idx = 1;
	while (row_idx < 5)
	{
		board[row_idx][5] = input[input_idx] - '0';
		input_idx += 2;
		row_idx++;
	}
}

void	fill_board_condition(int **board, char *input)
{
	fill_row_condition(board, input);
	fill_col_condition(board, input);
}
