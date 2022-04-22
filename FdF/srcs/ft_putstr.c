/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:06:32 by fde-albe          #+#    #+#             */
/*   Updated: 2022/03/07 15:06:38 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putstr(t_print *tab)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(tab->args, char *);
	if (s == NULL)
	{
		tab->lentot += write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	tab->lentot += i;
}
