/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:04:29 by fde-albe          #+#    #+#             */
/*   Updated: 2022/03/08 10:43:14 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(t_print *tab)
{
	unsigned char	a;

	a = (unsigned char)(va_arg(tab->args, int));
	tab->lentot += (write(1, &a, 1));
}
