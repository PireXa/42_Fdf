/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:56:27 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/26 10:47:51 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop(t_fdf *g)
{
	g->pxls = const_calc(g->dimen.c, g->dimen.l, g->pxls);
	calc_mesh(g->dimen, g->matriz, g->pxls);
	designer(g->dimen, g->matriz, g->img);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img.img, 0, 0);
	controls(g);
	mlx_loop(g->mlx);
}

int	main(int ac, char **av)
{
	t_fdf	*g;

	error_check(ac, av[1]);
	g = grf_initializer();
	g->pxls.map = av[1];
	g->dimen = dim_definer(g->pxls.map);
	g->matriz = allocate_matriz(g->dimen);
	g->pxls.off = offset_init(g->pxls.off);
	loop(g);
}
