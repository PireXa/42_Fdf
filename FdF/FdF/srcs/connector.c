/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slope.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:16:05 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/14 15:58:53 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	upper_davinci(t_kng xy, t_drw crd, t_data img)
{
	my_mlx_pixel_put(&img, ++xy.x_ple, xy.y_ple, MANGENTA);
	while (xy.x_ple != crd.x2 || xy.y_ple != crd.y2)
	{
		xy.s_plebeu = slope(crd.x1, crd.y1, xy.x_ple, xy.y_ple);
		if (xy.s_plebeu <= xy.s_rei)
			my_mlx_pixel_put(&img, ++xy.x_ple, xy.y_ple, MANGENTA);
		else
			my_mlx_pixel_put(&img, xy.x_ple, --xy.y_ple, MANGENTA);
	}
}

void	lower_davinci(t_kng xy, t_drw crd, t_data img)
{
	my_mlx_pixel_put(&img, ++xy.x_ple, ++xy.y_ple, MANGENTA);
	while (xy.x_ple != crd.x2 || xy.y_ple != crd.y2)
	{
		xy.s_plebeu = slope(crd.x1, crd.y1, xy.x_ple, xy.y_ple);
		if (xy.s_plebeu >= xy.s_rei)
			my_mlx_pixel_put(&img, ++xy.x_ple, xy.y_ple, MANGENTA);
		else
			my_mlx_pixel_put(&img, xy.x_ple, ++xy.y_ple, MANGENTA);
	}
}

void	connector(t_drw crd, t_data img)
{
	t_kng	xy;

	xy.x_ple = crd.x1;
	xy.y_ple = crd.y1;
	xy.s_rei = slope(crd.x1, crd.y1, crd.x2, crd.y2);
	if (xy.s_rei < 0.000)
		upper_davinci(xy, crd, img);
	else if (xy.s_rei > 0.000)
		lower_davinci(xy, crd, img);
	else
		while (xy.x_ple != crd.x2 || xy.y_ple != crd.y2)
			my_mlx_pixel_put(&img, ++xy.x_ple, xy.y_ple, MANGENTA);
}
