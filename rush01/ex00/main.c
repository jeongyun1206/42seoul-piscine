/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:40:08 by jnho              #+#    #+#             */
/*   Updated: 2022/09/04 21:48:34 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdlib.h>

void	make_board(int **board, int **visited, int row, int col);
void	fill_board_condition(int **board, char *input);

int	check_board(int argc, char **argv)
{
	int	argv_len;
	int	check_space;

	argv_len = 0;
	if (argc != 2)
		return (1);
	while (argv[1][argv_len])
		argv_len++;
	if (argv_len != 31)
		return (1);
	check_space = 1;
	while (check_space <= 29)
	{
		if (argv[1][check_space] != ' ')
			return (1);
		check_space += 2;
	}
	return (0);
}

int	**asign_board(void)
{
	int	**board;
	int	board_row_idx;
	int	init_row_idx;
	int	init_col_idx;

	board = (int **)malloc(sizeof(int *) * 6);
	board_row_idx = 0;
	while (board_row_idx < 6)
		board[board_row_idx++] = (int *)malloc(sizeof(int) * 6);
	init_row_idx = 0;
	init_col_idx = 0;
	while (init_row_idx <= 5)
	{
		while (init_col_idx <= 5)
		{
			board[init_row_idx][init_col_idx] = 0;
			init_col_idx++;
		}
		init_row_idx++;
	}
	return (board);
}

void	free_all_board(int **board, int **visited)
{
	int	idx;

	idx = 0;
	while (idx < 6)
	{
		free(board[idx]);
		free(visited[idx]);
		idx++;
	}
	free(board);
	free(visited);
	return ;
}

int	main(int argc, char **argv)
{
	int	**board;
	int	**visited;

	board = asign_board();
	visited = asign_board();
	if (check_board(argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fill_board_condition(board, argv[1]);
	make_board(board, visited, 1, 1);
	if (board[0][0] == 0)
		write(1, "Error\n", 6);
	free_all_board(board, visited);
}
