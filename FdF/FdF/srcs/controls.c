/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:27:54 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/15 12:44:49 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closex(void *param)
{
	(void)param;
	exit(0);
}

int	user_hook(int a, void *param)
{
	t_init_wind *g;

	g = (t_init_wind *)param;
	if (a == 53)
	{
		mlx_destroy_window(g->mlx, g->mlx_win);
		exit(0);
	}

	else if (a == 123)
	{
		ft_bzero(g->img.addr, WIND_H * WIND_W * (g->img.p / 8));
		g->pxls.x_off -= 10;
		g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
		g->pxls.colx -= 10;
		g->pxls.holdx = g->pxls.colx;
		g->matriz = calc_mesh(g->dimen, g->pxls.map, g->matriz, g->pxls);
		designer(g->dimen, g->matriz, g->img);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
	}
	else if (a == 124)
	{
		ft_bzero(g->img.addr, WIND_H * WIND_W * (g->img.p / 8));
		g->pxls.x_off += 10;
		g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
//		g->pxls.colx += 10;
//		g->pxls.holdx = g->pxls.colx;
		g->matriz = calc_mesh(g->dimen, g->pxls.map, g->matriz, g->pxls);
		designer(g->dimen, g->matriz, g->img);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
	}
	else if (a == 125)
	{
		ft_bzero(g->img.addr, WIND_H * WIND_W * (g->img.p / 8));
		g->pxls.y_off += 10;
		g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
//		g->pxls.liney += 10;
//		g->pxls.holdy = g->pxls.liney;
		g->matriz = calc_mesh(g->dimen, g->pxls.map, g->matriz, g->pxls);
		designer(g->dimen, g->matriz, g->img);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
	}
	else if (a == 126)
	{
		ft_bzero(g->img.addr, WIND_H * WIND_W * (g->img.p / 8));
		g->pxls.y_off -= 10;
		g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
//		g->pxls.liney -= 10;
//		g->pxls.holdy = g->pxls.liney;
		g->matriz = calc_mesh(g->dimen, g->pxls.map, g->matriz, g->pxls);
		designer(g->dimen, g->matriz, g->img);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
	}
	return (0);
}

void	controls(t_init_wind g)
{
	mlx_hook(g.mlx_win, 2, 0, user_hook, &g);
	mlx_hook(g.mlx_win, 3, 0, user_hook, &g);
	mlx_hook(g.mlx_win, 17, 0, closex, &g);
}
