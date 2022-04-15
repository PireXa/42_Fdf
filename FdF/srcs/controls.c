/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:27:54 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/15 11:31:04 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closex(void *param)
{
	(void)param;
	exit(0);
}

int	user_hook(int a, t_init_wind *g)
{
	if (a == 53)
	{
		mlx_destroy_window(g->mlx, g->mlx_win);
		exit(0);
	}
/*
	else if (a == 123)
	{
		matriz = calc_mesh(dimen, av[1], matriz, pxls);
		designer(dimen, matriz, g.img);
		mlx_put_image_to_window(g.mlx, g.mlx_win, g.img.img, 0, 0);
	}*/
	return (0);
}

void	controls(t_init_wind g)
{
	mlx_hook(g.mlx_win, 2, 1L << 0, user_hook, &g);
	mlx_hook(g.mlx_win, 17, 0, closex, &g);
}
