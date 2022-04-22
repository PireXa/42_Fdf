/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:06:00 by fde-albe          #+#    #+#             */
/*   Updated: 2022/03/07 15:06:06 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putsigned(t_print *tab)
{
	int		temp;
	char	*s;

	temp = va_arg(tab->args, int);
	s = ft_itoa(temp);
	tab->lentot += write(1, s, ft_strlen(s));
	free(s);
}
