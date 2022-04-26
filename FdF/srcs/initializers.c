/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:38:41 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/26 10:42:46 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dim	dim_definer(char *map)
{
	char	*line;
	int		fd;
	int		check;
	t_dim	dimen;

	dimen.c = 0;
	dimen.l = 0;
	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	check = valuescount(line);
	while (line)
	{
		dimen.c = valuescount(line);
		if (dimen.c != check)
		{
			ft_printf("\n\e[0;31mMap with different number of columns!\n\n");
			exit (0);
		}
		dimen.l++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (dimen);
}

t_trd	**allocate_matriz(t_dim dimen)
{
	int		a;
	t_trd	**matriz;

	a = -1;
	matriz = (t_trd **)malloc(sizeof(t_trd *) * dimen.l);
	if (!matriz)
		exit (0);
	while (++a < dimen.l)
	{
		matriz[a] = (t_trd *)malloc(sizeof(t_trd) * dimen.c + 1);
		if (!matriz[a])
			exit (0);
	}
	return (matriz);
}

t_off	offset_init(t_off off)
{
	off.zoom = 0;
	off.x_off = 0;
	off.y_off = 0;
	off.z_off = 1;
	off.r = 1;
	return (off);
}

t_fdf	*grf_initializer(void)
{
	t_fdf	*g;

	g = (t_fdf *)malloc(sizeof(t_fdf));
	g->mlx = mlx_init();
	g->mlx_win = mlx_new_window(g->mlx, WIND_W, WIND_H, "Fds");
	g->img.img = mlx_new_image(g->mlx, WIND_W, WIND_H);
	g->img.a = mlx_get_data_addr(g->img.img, &g->img.p, &g->img.l, &g->img.e);
	return (g);
}
