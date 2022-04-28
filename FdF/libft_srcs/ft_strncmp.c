/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:38:50 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 17:11:27 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i + 1 < n && ((unsigned char)s1[i] == (unsigned char)s2[i]
			&& ((unsigned char)s1[i]) && ((unsigned char)s2[i])))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
