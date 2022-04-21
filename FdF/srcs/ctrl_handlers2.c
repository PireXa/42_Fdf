/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_handlers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:02:25 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/21 13:11:20 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_z(int key, t_init_wind *g)
{
	reset_img(g);
	if (key == 34)
		g->pxls.off.z_off += 1;
	else if (key == 37)
		g->pxls.off.z_off -= 1;
	draw_model(g);
}

void	lines(int a, int x, int y, t_init_wind *g)
{
	int	b;

	b = 0;
	while (++a <= g->dimen.l)
	{
		while (b < (g->dimen.c - 1) * g->pxls.bargak / 5)
			my_mlx_pixel_put(&g->img, x + b++, y, 0x00FF00);
		b = 0;
		y = 100 + a * g->pxls.bargak / 5;
	}
}

void	columns(int a, int x, int y, t_init_wind *g)
{
	int	b;

	b = 0;
	while (++a <= g->dimen.c)
	{
		while (b < (g->dimen.l - 1) * g->pxls.bargak / 5)
			my_mlx_pixel_put(&g->img, x, y + b++, 0x00FF00);
		b = 0;
		x = 100 + a * g->pxls.bargak / 5;
	}
}

void	up_designer(t_init_wind *g)
{
	int	a;
	int	x;
	int	y;

	a = -1;
	x = 0;
	y = 0;
	reset_img(g);
	lines(a, x, y, g);
	columns(a, x, y, g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
}
