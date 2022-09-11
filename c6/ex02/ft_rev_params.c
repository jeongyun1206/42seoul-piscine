/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:25:24 by jnho              #+#    #+#             */
/*   Updated: 2022/09/05 14:28:59 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char *argv)
{
	int	idx;

	idx = 0;
	while (argv[idx])
	{
		write(1, argv + idx, 1);
		idx++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	argv_idx;

	argv_idx = argc - 1;
	while (argv_idx > 0)
	{
		ft_putchar(argv[argv_idx]);
		argv_idx--;
	}
}
