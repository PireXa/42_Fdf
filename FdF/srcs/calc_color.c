/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:22:56 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/21 12:52:32 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pos(char c)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if ("0123456789ABCDEF"[i] == c)
			return (i);
		else if ("0123456789abcdef"[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

char	*ft_pro_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i + 3));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i + 3));
	return (NULL);
}

int	hex_decode(char *f)
{
	int	i;
	int	res;
	int	size;

	i = -1;
	res = 0;
	size = ft_strlen(f);
	while (++i < size && f[i] != '\0')
		res = res + (pos(f[i]) * ft_recursive_power(16, (size - i - 1)));
	return (res);
}

int	color_reader(char	*s)
{
	int		res;
	char	*f;

	res = 0;
	f = ft_pro_strchr(s, ',');
	if (f == NULL)
		return (-1);
	res = hex_decode(f);
	return (res);
}
