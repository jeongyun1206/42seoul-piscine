/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnho <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:10:08 by jnho              #+#    #+#             */
/*   Updated: 2022/09/10 14:21:16 by jnho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	ft_base_confirm(char *base);

char	*malloc_rtn_nbr(int nbr_to_int, int base_to_len)
{
	char	*rtn_nbr;
	int		rtn_nbr_len;
	int		sign;

	if (nbr_to_int == 0)
		rtn_nbr = (char *)malloc(sizeof(char) * 2);
	if (nbr_to_int == 0 && !rtn_nbr)
		return (0);
	sign = 0;
	if (nbr_to_int < 0)
		sign = 1;
	rtn_nbr_len = 0;
	while (nbr_to_int)
	{
		rtn_nbr_len++;
		nbr_to_int /= base_to_len;
	}
	rtn_nbr = (char *)malloc(sizeof(char) * (rtn_nbr_len + sign + 1));
	if (!rtn_nbr)
		return (0);
	return (rtn_nbr);
}

int	ft_rtn_len(int base_to_len, int nbr_to_int)
{
	int	rtn_nbr_len;

	rtn_nbr_len = 0;
	if (nbr_to_int == 0)
		return (1);
	while (nbr_to_int)
	{
		rtn_nbr_len++;
		nbr_to_int /= base_to_len;
	}
	return (rtn_nbr_len);
}

void	ft_nbr_to_base(int nbr_to_int, char *base_to, char *rtn_nbr)
{
	int	rtn_idx;
	int	base_len;
	int	rtn_len;

	base_len = 0;
	while (base_to[base_len])
		base_len++;
	rtn_len = ft_rtn_len(base_len, nbr_to_int);
	rtn_idx = 0;
	if (nbr_to_int < 0)
	{
		rtn_nbr[rtn_idx] = '-';
		rtn_len++;
	}
	if (nbr_to_int == 0)
		rtn_nbr[rtn_idx] = base_to[0];
	rtn_nbr[rtn_len] = '\0';
	while (nbr_to_int && ++rtn_idx)
	{
		if (nbr_to_int < 0)
			rtn_nbr[rtn_len - rtn_idx] = base_to[-1 * (nbr_to_int % base_len)];
		else
			rtn_nbr[rtn_len - rtn_idx] = base_to[nbr_to_int % base_len];
		nbr_to_int /= base_len;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_to_int;
	char	*rtn_nbr;
	int		base_to_len;
	int		base_from_len;

	if (!base_from || !base_to)
		return (NULL);
	nbr_to_int = ft_atoi_base(nbr, base_from);
	base_to_len = ft_base_confirm(base_to);
	base_from_len = ft_base_confirm(base_from);
	if (base_from_len < 2 || base_to_len < 2)
		return (NULL);
	rtn_nbr = malloc_rtn_nbr(nbr_to_int, base_to_len);
	if (!rtn_nbr)
		return (0);
	ft_nbr_to_base(nbr_to_int, base_to, rtn_nbr);
	return (rtn_nbr);
}
