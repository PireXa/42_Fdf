/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valuescount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:06:22 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 17:14:44 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	valuescount(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (!(ft_isspace(s[i])) && s[i] != '\0')
			i++;
		while (ft_isspace(s[i]) && s[i] != '\0')
			i++;
		count++;
	}
	if (!(ft_isdigit(s[0]) || s[0] == '-'))
		count--;
	return (count);
}
