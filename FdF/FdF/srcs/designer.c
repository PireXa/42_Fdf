/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   designer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:41:37 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/13 15:42:08 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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