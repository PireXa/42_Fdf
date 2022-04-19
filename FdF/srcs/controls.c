/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:27:54 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/19 16:51:09 by fde-albe         ###   ########.fr       */
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
	if (a == 123 || a == 124 || a == 125 || a == 126)
		move_model(a, g);
	else if (a == 6)
	{
		ft_bzero(g->img.addr, WIND_H * WIND_W * (g->img.p / 8));
	//	g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
		g->pxls.bargak *= 2;
		calc_mesh(g->dimen, g->matriz, g->pxls);
		designer(g->dimen, g->matriz, g->img);
		mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
	}
	else if (a == 11)
		color_change(a, g);
	return (0);
}

void	controls(t_init_wind g)
{
	mlx_hook(g.mlx_win, 2, 0, user_hook, &g);
//	mlx_hook(g.mlx_win, 3, 0, user_hook, &g);
	mlx_hook(g.mlx_win, 17, 0, closex, &g);
}
