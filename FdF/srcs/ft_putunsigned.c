/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:06:59 by fde-albe          #+#    #+#             */
/*   Updated: 2022/03/07 15:07:10 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_putunsigned(t_print *tab)
{
	unsigned int	temp;
	char			*s;

	temp = va_arg(tab->args, unsigned int);
	s = ft_uitoa(temp);
	tab->lentot += write(1, s, ft_strlen(s));
	free(s);
}
