/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:41:37 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 10:19:16 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_cmp(int a, int b)
{
	if (a == b && a != -1)
		return (1);
	return (0);
}

void	dsg_lines(t_dim dimen, t_trd **m, t_data img, t_drw drw)
{
	int	b;

	b = -1;
	while (++b < dimen.c - 1)
	{
		drw.x1 = m[drw.a][b].x;
		drw.y1 = m[drw.a][b].y;
		drw.x2 = m[drw.a][b + 1].x;
		drw.y2 = m[drw.a][b + 1].y;
		if (color_cmp(m[drw.a][b].clr, m[drw.a][b + 1].clr))
			img.clr = m[drw.a][b].clr;
		else
			img.clr = 0x4876ff;
		connector(drw, img);
	}
}

void	dsg_columns(t_dim dimen, t_trd **m, t_data img, t_drw drw)
{
	int	b;

	b = -1;
	while (++b < dimen.c)
	{
		drw.x1 = m[drw.a][b].x;
		drw.y1 = m[drw.a][b].y;
		drw.x2 = m[drw.a + 1][b].x;
		drw.y2 = m[drw.a + 1][b].y;
		if (color_cmp(m[drw.a][b].clr, m[drw.a + 1][b].clr))
			img.clr = m[drw.a][b].clr;
		else
			img.clr = 0x4876ff;
		connector(drw, img);
	}
}

void	designer(t_dim dimen, t_trd **m, t_data img)
{
	t_drw	drw;

	drw.a = -1;
	while (++drw.a < dimen.l)
		dsg_lines(dimen, m, img, drw);
	drw.a = -1;
	while (++drw.a < dimen.l - 1)
		dsg_columns(dimen, m, img, drw);
}
