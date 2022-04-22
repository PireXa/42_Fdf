/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:38:41 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 11:40:43 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_off	offset_init(t_off off)
{
	off.zoom = 0;
	off.x_off = 0;
	off.y_off = 0;
	off.z_off = 1;
	off.r = 1;
	return (off);
}

t_fdf	grf_initializer(void)
{
	t_fdf	g;

	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, WIND_W, WIND_H, "Fds");
	g.img.img = mlx_new_image(g.mlx, WIND_W, WIND_H);
	g.img.addr = mlx_get_data_addr(g.img.img, &g.img.p, &g.img.lgt, &g.img.e);
	return (g);
}
