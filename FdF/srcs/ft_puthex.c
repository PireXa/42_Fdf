/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:04:50 by fde-albe          #+#    #+#             */
/*   Updated: 2022/03/08 17:21:47 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	ft_newstrlen(unsigned int temp)
{
	int	i;

	i = 0;
	while (temp > 15)
	{
		temp /= 16;
		i++;
	}
	return (i);
}

void	ft_puthex(t_print *tab)
{
	unsigned int	n;
	char			*a;
	int				i;
	unsigned int	temp;

	i = 0;
	n = va_arg(tab->args, int);
	temp = n;
	if (n < 0)
	{
		tab->lentot += write(1, "-", 1);
		n *= (-1);
		i++;
	}
	i = ft_newstrlen(temp);
	a = (char *)ft_calloc(i + 1, sizeof(char *));
	while (n >= 0 && i >= 0)
	{
		a[i--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	tab->lentot += write(1, a, ft_strlen(a));
	free(a);
}
