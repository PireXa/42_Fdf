/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valuescount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:24:32 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/08 13:51:11 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	valuescount(char *s)
{
/*	int	i;
	int	count;

	count = 0;
	i = 0;

	while(s[i] != '\0')
	{
		while ((s[i] >= 48 && s[i] <= 57 || s[i] == '-') && s[i] != '\0')
			i++;
		while(!(s[i] >= 48 && s[i] <= 57 || s[i] == '-') && s[i] != '\0')
			i++;;
		count++;
		i++;
	}

	return (count);
*/

	int	i;
	int	count;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
		{	
			i++;
			flag = 1;
		}
//		printf("flag: %d\n", flag);
		while (!(s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
		{
			i++;
			flag = 0;
		}
		count++;
	}
//	printf("flag: %d\n", flag);
	if (flag == 1)
		count--;
	return (count);

}
