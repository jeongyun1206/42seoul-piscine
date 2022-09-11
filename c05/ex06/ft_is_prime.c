/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:43:58 by jnho              #+#    #+#             */
/*   Updated: 2022/09/06 17:54:38 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_num(int nb)
{
	int	sqrt;

	sqrt = 1;
	while (sqrt < nb)
	{
		if (nb / sqrt <= sqrt)
			return (sqrt);
		sqrt++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt_num;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (0);
	i = 2;
	sqrt_num = ft_sqrt_num(nb);
	while (i <= sqrt_num)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
