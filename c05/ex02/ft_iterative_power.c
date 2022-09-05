/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:54:34 by jnho              #+#    #+#             */
/*   Updated: 2022/09/01 20:28:02 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	temp_nb;

	temp_nb = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power - 1)
	{
		nb *= temp_nb;
		power--;
	}
	return (nb);
}
