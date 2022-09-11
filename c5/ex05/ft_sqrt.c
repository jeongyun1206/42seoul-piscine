/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:41:44 by jnho              #+#    #+#             */
/*   Updated: 2022/09/07 13:41:55 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqrt;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	sqrt = 1;
	while (sqrt <= nb / sqrt)
	{
		if (nb / sqrt == sqrt && nb % sqrt == 0)
			return (sqrt);
		sqrt++;
	}
	return (0);
}