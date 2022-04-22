/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:05:38 by fde-albe          #+#    #+#             */
/*   Updated: 2022/03/14 13:00:12 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_s(int i, long unsigned temp, char *s)
{
	while (temp > 0)
	{
		s[i--] = "0123456789abcdef"[temp % 16];
		temp /= 16;
	}
	return (s);
}

void	ft_putptr(t_print *tab)
{
	long unsigned			temp;
	char					*s;
	int						i;
	long unsigned			ptr;

	i = 3;
	ptr = va_arg(tab->args, long);
	temp = ptr;
	while (temp > 15 && i++)
		temp /= 16;
	s = (char *)ft_calloc(i, sizeof(char *));
	s[0] = '0';
	s[1] = 'x';
	if (temp == 0)
	{
		s[2] = '0';
		tab->lentot += write(1, s, ft_strlen(s));
		free(s);
		return ;
	}
	temp = ptr;
	i -= 1;
	s = make_s(i, temp, s);
	tab->lentot += write(1, s, ft_strlen(s));
	free(s);
}
