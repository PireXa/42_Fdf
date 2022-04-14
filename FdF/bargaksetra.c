/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bargaksetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:28:06 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/14 13:53:50 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

short	ft_abs(short n)
{
	if (n < 0)
		return (-n);
	return (n);
}

short	calc_max_height(short columns, short lines, char *map)
{
	short fd = open(map, O_RDWR);
	short a = -1;
	short b = 0;
	short c = 0;
	char	**hold = 0;
	char	*line = get_next_line(fd);
	while (line)
	{
		hold = ft_split(line, 32);
		while (++a < columns)
		{
			c = ft_abs(ft_atoi(hold[a]));
			if (b < c)
					b = c;
		}
		line = get_next_line(fd);
		a = -1;
	}
	close(fd);
	return (b);
}

t_pxls	bargak_calc(short columns, short lines, t_pxls pxls)
{
	short	h = 0;

	pxls.bargak = 0;
	h = calc_max_height(columns, lines, pxls.map);
	if (columns >= lines)
		pxls.bargak = columns;
	else
		pxls.bargak = lines;
//	printf("bargak = %d\n", pxls.bargak);
	if (pxls.bargak <= 15)
		pxls.bargak = 320;
	else if (pxls.bargak <= 30)
		pxls.bargak = 160;
	else if (pxls.bargak <= 45)
		pxls.bargak = 100;
	else if (pxls.bargak <= 60)
		pxls.bargak = 60;
	else if (pxls.bargak <= 100)
		pxls.bargak = 40;
	else
		pxls.bargak = 20;
	pxls.colx = 960;
	pxls.liney = 1000;
	pxls.holdx = pxls.colx;
	pxls.holdy = pxls.liney;
	if (h > 20)
	{
		pxls.bargak = 20;
		pxls.colx = 960;
		pxls.liney = 590;
		pxls.holdx = pxls.colx;
		pxls.holdy = pxls.liney;

	}
	printf("h = %d\nbargak = %d\n", h, pxls.bargak);
	return (pxls);
}
