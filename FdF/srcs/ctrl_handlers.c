/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:24:06 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/20 15:59:45 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_img(t_init_wind *g)
{
	ft_bzero(g->img.addr, WIND_H * WIND_W * (g->img.p / 8));
}

void	draw_model(t_init_wind *g)
{
	g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
	calc_mesh(g->dimen, g->matriz, g->pxls);
	designer(g->dimen, g->matriz, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}

void	color_change(int key, t_init_wind *g)
{
	if (key == 11)
	{
		g->img.clr = 0x000049FF;
		calc_mesh(g->dimen, g->matriz, g->pxls);
		designer(g->dimen, g->matriz, g->img);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
	}
}

void	zoom(int key, t_init_wind *g)
{
	reset_img(g);
	if (key == 6)
	{
		g->pxls.off.zoom *= 1.3;
		draw_model(g);
	}
	else if (key == 7)
	{
		g->pxls.off.zoom /= 1.3;
		draw_model(g);
	}
}

void	move_model(int key, t_init_wind *g)
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
