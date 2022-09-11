/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:08:15 by jnho              #+#    #+#             */
/*   Updated: 2022/09/05 14:26:42 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*f_name;
	int		idx;

	idx = 0;
	if (argc < 0)
		return (0);
	f_name = argv[0];
	while (f_name[idx])
	{
		write(1, f_name + idx, 1);
		idx++;
	}
	write(1, "\n", 1);
}
