/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 13:05:30 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 09:54:50 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	slope(float x1, int y1, int x2, int y2)
{
	float	ret;

	ret = (y2 - y1) / (x2 - x1);
	return (ret);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIND_W && y >= 0 && y < WIND_H)
	{
		dst = data->addr + (y * data->lgt + x * (data->p / 8));
		*(unsigned int *)dst = color;
	}
}

void	upper_davinci(t_kng xy, t_drw crd, t_data img)
{
	my_mlx_pixel_put(&img, ++xy.x_ple, xy.y_ple, img.clr);
	while (xy.x_ple != crd.x2 || xy.y_ple != crd.y2)
	{
		xy.s_plebeu = slope(crd.x1, crd.y1, xy.x_ple, xy.y_ple);
		if (xy.s_plebeu <= xy.s_rei)
			my_mlx_pixel_put(&img, ++xy.x_ple, xy.y_ple, img.clr);
		else
			my_mlx_pixel_put(&img, xy.x_ple, --xy.y_ple, img.clr);
	}
}

void	lower_davinci(t_kng xy, t_drw crd, t_data img)
{
	my_mlx_pixel_put(&img, ++xy.x_ple, ++xy.y_ple, img.clr);
	while (xy.x_ple != crd.x2 || xy.y_ple != crd.y2)
	{
		xy.s_plebeu = slope(crd.x1, crd.y1, xy.x_ple, xy.y_ple);
		if (xy.s_plebeu >= xy.s_rei)
			my_mlx_pixel_put(&img, ++xy.x_ple, xy.y_ple, img.clr);
		else
			my_mlx_pixel_put(&img, xy.x_ple, ++xy.y_ple, img.clr);
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
			my_mlx_pixel_put(&img, ++xy.x_ple, xy.y_ple, img.clr);
}
