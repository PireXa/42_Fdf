/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:56:27 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/14 15:14:59 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, short x, short y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->lgt + x * (data->p / 8));
	*(unsigned int *)dst = color;
}

float	slope(float x1, short y1, short x2, short y2)
{
	float	ret;

	ret = (y2 - y1) / (x2 - x1);
	return (ret);
}

t_init_wind	grf_initializer(void)
{
	t_init_wind	g;

	g.mlx = mlx_init();
	g.mlx_win = mlx_new_window(g.mlx, 1920, 1080, "Fds");
	g.img.img = mlx_new_image(g.mlx, 1920, 1080);
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
	t_dim		dimen;
	short		a;
	t_trd		**matriz;
	t_pxls		pxls;
	t_init_wind	g;

	pxls.map = av[1];
	a = -1;
	if (ac != 2)
		return (0);
	dimen = dim_definer(av[1]);
	g = grf_initializer();
	matriz = malloc(sizeof(t_trd *) * dimen.l);
	while (++a < dimen.l)
		matriz[a] = malloc(sizeof(t_trd) * dimen.c + 1);
	pxls = bargak_calc(dimen.c, dimen.l, pxls);
	matriz = calc_mesh(dimen, av[1], matriz, pxls);
	designer(dimen, matriz, g.img);
	mlx_put_image_to_window(g.mlx, g.mlx_win, g.img.img, 0, 0);
	mlx_loop(g.mlx);
}
