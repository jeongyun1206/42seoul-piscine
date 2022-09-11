/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:39:44 by youngkpa          #+#    #+#             */
/*   Updated: 2022/09/04 16:59:49 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	make_exist_arr(int *is_exist)
{
	int	idx;

	idx = 0;
	while (idx < 4)
	{
		is_exist[idx] = 0;
		idx++;
	}
}

int	ft_check_1234(int **board)
{
	int	row_idx;
	int	col_idx;
	int	is_exist[4];
	int	now_num;

	col_idx = 1;
	while (col_idx <= 4)
	{
		row_idx = 1;
		make_exist_arr(is_exist);
		while (row_idx <= 4)
		{
			now_num = board[row_idx][col_idx];
			if (now_num == 0)
				break ;
			if (is_exist[now_num - 1] == 1)
				return (0);
			is_exist[now_num - 1] = 1;
			row_idx++;
		}
		col_idx++;
	}
	return (1);
}

int	ft_visible_num(int *line, int idx)
{
	int	visible_num;
	int	highest;
	int	cnt;
	int	direction;

	visible_num = 0;
	highest = 0;
	cnt = 0;
	if (idx == 1)
		direction = 1;
	else if (idx == 4)
		direction = -1;
	while (cnt <= 3)
	{
		if (line[idx] > highest)
		{
			highest = line[idx];
			visible_num += 1;
		}
		cnt++;
		idx += direction;
	}
	return (visible_num);
}

int	ft_check_line(int *line)
{
	if (line[0] != ft_visible_num(line, 1))
		return (0);
	if (line[5] != ft_visible_num(line, 4))
		return (0);
	return (1);
}

int	ft_check_proper(int	**board)
{	
	int	line[6];
	int	idx;

	idx = 1;
	while (idx <= 4)
	{
		if (!ft_check_line(board[idx]))
			return (0);
		idx++;
	}
	idx = 1;
	while (idx <= 4)
	{
		line[0] = board[0][idx];
		line[1] = board[1][idx];
		line[2] = board[2][idx];
		line[3] = board[3][idx];
		line[4] = board[4][idx];
		line[5] = board[5][idx];
		if (!ft_check_line(line))
			return (0);
		idx++;
	}
	board[0][0] = 1;
	return (1);
}
