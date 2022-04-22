/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_handlers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:02:25 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 17:59:04 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_z(int key, t_fdf *g)
{
	reset_img(g);
	if (key == 34 && g->pxls.off.z_off < 10)
			g->pxls.off.z_off += 1;
	else if (key == 37 && g->pxls.off.z_off > -10)
			g->pxls.off.z_off -= 1;
	draw_model(g);
}

void	base_mesh(int key, t_fdf *g)
{
	reset_img(g);
	if (key == 11)
		g->pxls.off.r = 0;
	else
		g->pxls.off.r = 1;
	draw_model(g);
}

void	lines(int a, int x, int y, t_fdf *g)
{
	int	b;
	int	p;

	b = -1;
	p = -1;
	while (a < g->dimen.l)
	{
		while (++b < g->dimen.c - 1)
		{
			if (color_cmp(g->matriz[a][b].clr, g->matriz[a][b + 1].clr))
				g->img.clr = g->matriz[a][b].clr;
			else
				g->img.clr = 0x4876ff;
			while (++p < g->pxls.bargak)
				my_mlx_pixel_put(&g->img, x + p, y, g->img.clr);
			p = -1;
			x += g->pxls.bargak;
		}
		x = 100 + g->pxls.off.x_off;
		p = -1;
		b = -1;
		y = 100 + g->pxls.off.y_off + ++a * g->pxls.bargak;
	}
}

void	columns(int a, int x, int y, t_fdf *g)
{
	int	b;
	int	p;

	b = -1;
	p = -1;
	while (a < g->dimen.c)
	{
		while (++b < g->dimen.l - 1)
		{
			if (color_cmp(g->matriz[b][a].clr, g->matriz[b + 1][a].clr))
				g->img.clr = g->matriz[b][a].clr;
			else
				g->img.clr = 0x4876ff;
			while (++p < g->pxls.bargak)
					my_mlx_pixel_put(&g->img, x, y + p, g->img.clr);
			p = -1;
			y += g->pxls.bargak;
		}
		y = 100 + g->pxls.off.y_off;
		p = -1;
		b = -1;
		x = 100 + g->pxls.off.x_off + ++a * g->pxls.bargak;
	}
}

void	up_designer(t_fdf *g)
{
	int	a;
	int	x;
	int	y;

	a = 0;
	x = 100 + g->pxls.off.x_off;
	y = 100 + g->pxls.off.y_off;
	reset_img(g);
	calc_mesh(g->dimen, g->matriz, g->pxls);
	lines(a, x, y, g);
	columns(a, x, y, g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}
