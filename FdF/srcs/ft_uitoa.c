/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:35:30 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 16:47:07 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	newstrlen(long c)
{
	int	i;

	i = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		c /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int c)
{
	char	*res;
	int		n;
	long	new_c;

	new_c = c;
	n = newstrlen(new_c);
	res = malloc(sizeof(char) * n + 1);
	if (!res)
		return (NULL);
	if (new_c == 0)
		res[0] = '0';
	res[n] = '\0';
	while (new_c > 0)
	{
		res[n - 1] = new_c % 10 + '0';
		new_c /= 10;
		n--;
	}
	return (res);
}
