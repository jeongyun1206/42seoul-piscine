/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:28:05 by jnho              #+#    #+#             */
/*   Updated: 2022/09/14 14:47:03 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

char	**get_map_by_file(char *file_name, int *map_info_arr);
int		get_map_info(char *initial, int *info, int *total_len);
int		get_confirm_map(char *map_initial, int *map_info_arr);
char	**get_fill_map(char *map_initial, int *map_info_arr);
void	square(char **map, int *map_info_arr);
void	prt_biggest_square(char **map, int **dp_map, int *map_info_arr);

#endif
