/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:56:27 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/18 10:14:36 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIND_W && y >= 0 && y < WIND_H)
	{
		dst = data->addr + (y * data->lgt + x * (data->p / 8));
		*(unsigned int *)dst = color;
	}
}

float	slope(float x1, int y1, int x2, int y2)
{
	float	ret;

	ret = (y2 - y1) / (x2 - x1);
	return (ret);
}

t_init_wind	grf_initializer(void)
{
	t_init_wind	g;

	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, WIND_W, WIND_H, "Fds");
	g.img.img = mlx_new_image(g.mlx, WIND_W, WIND_H);
	g.img.addr = mlx_get_data_addr(g.img.img, &g.img.p, &g.img.lgt, &g.img.e);
	return (g);
}

t_dim	dim_definer(char *map)
{
	char		*line;
	int			fd;
	t_dim		dimen;

	dimen.c = 0;
	dimen.l = 0;
	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		dimen.c = valuescount(line);
		dimen.l++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (dimen);
}

int	main(int ac, char **av)
{
	int		a;
	t_init_wind	g;

	g.pxls.map = av[1];
	a = -1;
	if (ac != 2)
		return (0);
	g = grf_initializer();
	g.pxls.map = av[1];
	g.dimen = dim_definer(av[1]);
	g.matriz = malloc(sizeof(t_trd *) * g.dimen.l);
	if (!g.matriz)
		return (0);
	while (++a < g.dimen.l)
		g.matriz[a] = malloc(sizeof(t_trd) * g.dimen.c + 1);
	g.pxls.x_off = 0;
	g.pxls.y_off = 0;
	g.pxls = const_calc(g.dimen.c, g.dimen.l, g.pxls);
	calc_mesh(g.dimen, av[1], g.matriz, g.pxls);
	designer(g.dimen, g.matriz, g.img);
	mlx_put_image_to_window(g.mlx, g.mlx_win, g.img.img, 0, 0);
	controls(g);
	mlx_loop(g.mlx);
	free(g.matriz);
}
