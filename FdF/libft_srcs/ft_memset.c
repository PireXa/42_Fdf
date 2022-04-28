/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:29:12 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 16:45:00 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char	*ptr;

	ptr = dest;
	while (len-- > 0)
		*ptr++ = val;
	return (dest);
}
