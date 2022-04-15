/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:10:38 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/15 12:41:51 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

short	ft_abs(short n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_pxls	calc_start_pxls(t_pxls pxls, short h)
{
	pxls.colx = (WIND_W / 2) + pxls.x_off;
	pxls.liney = WIND_H - 80 + pxls.y_off;
	pxls.holdx = pxls.colx;
	pxls.holdy = pxls.liney;
	if (h > 20)
	{
		pxls.bargak = 50;
		pxls.colx = WIND_W / 2;
		pxls.liney = WIND_H / 2;
		pxls.holdx = pxls.colx;
		pxls.holdy = pxls.liney;
	}
	return (pxls);
}

short	calc_max_height(short columns, char *map)
{
	t_ctr	cnt;
	short	fd;
	char	**hold;
	char	*line;

	fd = open(map, O_RDWR);
	cnt.a = -1;
	cnt.b = 0;
	cnt.c = 0;
	hold = 0;
	line = get_next_line(fd);
	while (line)
	{
		hold = ft_split(line, 32);
		while (++cnt.a < columns)
		{
			cnt.c = ft_abs(ft_atoi(hold[cnt.a]));
			if (cnt.b < cnt.c)
				cnt.b = cnt.c;
		}
		line = get_next_line(fd);
		cnt.a = -1;
	}
	close(fd);
	return (cnt.b);
}

t_pxls	const_calc(short columns, short lines, t_pxls pxls)
{
	short	h;

	h = 0;
	pxls.bargak = 0;
	h = calc_max_height(columns, pxls.map);
	if (columns >= lines)
		pxls.bargak = columns;
	else
		pxls.bargak = lines;
	if (pxls.bargak <= 15)
		pxls.bargak = 320;
	else if (pxls.bargak <= 30)
		pxls.bargak = 200;
	else if (pxls.bargak <= 45)
		pxls.bargak = 100;
	else if (pxls.bargak <= 60)
		pxls.bargak = 60;
	else if (pxls.bargak <= 100)
		pxls.bargak = 40;
	else
		pxls.bargak = 20;
	pxls = calc_start_pxls(pxls, h);
	return (pxls);
}