/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:28:05 by jnho              #+#    #+#             */
/*   Updated: 2022/09/12 21:28:09 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SQUARE_H
# define FT_HEADER_H

void	square(char **map, int *map_info_arr)
int		**make_dp_map(char **map, int *map_info_arr)
int		**malloc_dp_map(int *map_info_arr)
void	fill_dp_map(int **dp_map, int *map_info_arr)
int		dp_size(int **dp_map, int row_idx, int col_idx)
void	prt_bigest_square(char **map, int **dp_map, int *map_info_arr)
void	find_bigest_square(int **dp_map, int *bigest_info_arr, int *map_info_arr)
void	fill_map(char **map, int *bigest_info_arr, int *map_info_arr)
void	prt_map(char **map, int *map_info_arr)

#endif
