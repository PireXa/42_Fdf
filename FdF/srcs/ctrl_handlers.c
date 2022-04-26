/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:24:06 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/26 10:32:30 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_img(t_fdf *g)
{
	ft_bzero(g->img.a, WIND_H * WIND_W * (g->img.p / 8));
}

void	draw_model(t_fdf *g)
{
	g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
	calc_mesh(g->dimen, g->matriz, g->pxls);
	designer(g->dimen, g->matriz, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

void	up_view(t_fdf *g)
{
	reset_img(g);
	g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
	up_designer(g);
}

void	zoom(int key, t_fdf *g)
{
	reset_img(g);
	printf("");
	if (key == 6)
	{
		if (g->pxls.bargak < 100)
			g->pxls.off.zoom += 1;
		draw_model(g);
	}
	else if (key == 7)
	{
		if (!(g->pxls.off.zoom <= -g->pxls.bargak))
			g->pxls.off.zoom -= 1;
		draw_model(g);
	}
}

void	move_model(int key, t_fdf *g)
{
	reset_img(g);
	if (key == 123)
	{
		g->pxls.off.x_off -= 10;
		draw_model(g);
	}
	else if (key == 124)
	{
		g->pxls.off.x_off += 10;
		draw_model(g);
	}
	else if (key == 125)
	{
		g->pxls.off.y_off += 10;
		draw_model(g);
	}
	else if (key == 126)
	{
		g->pxls.off.y_off -= 10;
		draw_model(g);
	}
}
