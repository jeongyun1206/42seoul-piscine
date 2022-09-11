/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:13:20 by jnho              #+#    #+#             */
/*   Updated: 2022/09/01 21:18:25 by jnho             ###   ########.fr       */
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

int	ft_is_prime_num(int nb)
{
	int	i;
	int	prime;
	int	sqrt_num;

	sqrt_num = ft_sqrt_num(nb);
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (0);
	i = 2;
	while (i <= sqrt_num)
	{
		prime = nb / i;
		if (prime * i == nb)
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (ft_is_prime_num(nb))
		nb++;
	return (nb);
}
