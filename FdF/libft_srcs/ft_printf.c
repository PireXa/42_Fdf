/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:36:02 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 16:46:52 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_print	*ft_initialise_tab(t_print *tab)
{
	tab->lentot = 0;
	return (tab);
}

static void	ft_format(char formater, t_print *tab)
{
	if (formater == 'c')
		ft_putchar(tab);
	else if (formater == 's')
		ft_putstr(tab);
	else if (formater == 'p')
		ft_putptr(tab);
	else if (formater == 'd' || formater == 'i')
		ft_putsigned(tab);
	else if (formater == 'u')
		ft_putunsigned(tab);
	else if (formater == 'x')
		ft_puthex(tab);
	else if (formater == 'X')
		ft_puthexup(tab);
	else if (formater == '%')
		tab->lentot += write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	t_print	*tab;
	int		ret;

	i = 0;
	ret = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_format(str[++i], tab);
		else
			ret += write(1, &str[i], 1);
		i++;
	}
	va_end(tab->args);
	ret += tab->lentot;
	free(tab);
	return (ret);
}
