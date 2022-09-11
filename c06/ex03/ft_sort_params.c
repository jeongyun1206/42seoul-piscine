/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:27:54 by jnho              #+#    #+#             */
/*   Updated: 2022/09/05 15:41:46 by jnho             ###   ########.fr       */
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

int	cmp_argv(char *argv_f, char *argv_b)
{
	int	argv_idx;

	argv_idx = 0;
	while (argv_f[argv_idx] == argv_b[argv_idx])
		argv_idx++;
	if (argv_f[argv_idx] > argv_b[argv_idx])
		return (1);
	else
		return (0);
}

void	sort_argc(int argc, char **argv)
{
	int		idx;
	int		not_sorted;
	char	*buff;

	not_sorted = argc - 1;
	if (not_sorted < 1)
	{
		return ;
	}
	while (not_sorted)
	{
		idx = 1;
		while (idx < not_sorted)
		{
			if (cmp_argv(argv[idx], argv[idx + 1]))
			{
				buff = argv[idx];
				argv[idx] = argv[idx + 1];
				argv[idx + 1] = buff;
			}
			idx++;
		}
		not_sorted--;
	}
}

int	main(int argc, char **argv)
{
	int	argv_idx;

	sort_argc(argc, argv);
	argv_idx = 1;
	while (argv_idx < argc)
	{
		ft_putchar(argv[argv_idx]);
		argv_idx++;
	}
}
