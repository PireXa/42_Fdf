/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:10:38 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/26 10:34:19 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pxls	calc_start_pxls(t_pxls pxls, int h)
{
	pxls.colx = (WIND_W / 2) + pxls.off.x_off;
	pxls.liney = (WIND_H - 80) + pxls.off.y_off;
	pxls.holdx = pxls.colx;
	pxls.holdy = pxls.liney;
	if (h >= 100)
		pxls.bargak = 2;
	else if (h >= 40)
		pxls.bargak = 3;
	return (pxls);
}

t_ctr	height_extra(t_ctr cnt, char **hold)
{
	cnt.a = -1;
	while (hold[++cnt.a])
	{
		cnt.c = ft_atoi(hold[cnt.a]);
		if (cnt.b < cnt.c)
			cnt.b = cnt.c;
		else if (cnt.d > cnt.c)
			cnt.d = cnt.c;
	}
	return (cnt);
}

int	calc_max_height(char *map)
{
	t_ctr	cnt;
	int		fd;
	char	**hold;
	char	*line;

	fd = open(map, O_RDWR);
	cnt.b = 0;
	cnt.c = 0;
	cnt.d = 0;
	hold = 0;
	line = get_next_line(fd);
	while (line)
	{
		hold = ft_split(line, 32);
		cnt = height_extra(cnt, hold);
		free (hold);
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	return (cnt.b - cnt.d);
}

t_pxls	const_calc(int columns, int lines, t_pxls pxls)
{
	int	h;

	h = 0;
	pxls.bargak = 0;
	h = calc_max_height(pxls.map);
	if (columns >= lines)
		pxls.bargak = columns;
	else
		pxls.bargak = lines;
	if (pxls.bargak <= 15)
		pxls.bargak = 30;
	else if (pxls.bargak <= 30)
		pxls.bargak = 20;
	else if (pxls.bargak <= 45)
		pxls.bargak = 10;
	else if (pxls.bargak <= 60)
		pxls.bargak = 6;
	else if (pxls.bargak <= 100)
		pxls.bargak = 3;
	else
		pxls.bargak = 2;
	pxls = calc_start_pxls(pxls, h);
	pxls.bargak += pxls.off.zoom;
	return (pxls);
}
