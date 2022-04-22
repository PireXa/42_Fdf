/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:56:27 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 17:24:01 by fde-albe         ###   ########.fr       */
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
			dimen.c = -1;
			return (dimen);
		}
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
	t_fdf	g;

	a = -1;
	if (ft_error(g.dimen.c) || error_check(ac, av[1]))
		return (0);
	g = grf_initializer();
	g.pxls.map = av[1];
	g.dimen = dim_definer(g.pxls.map);
	g.matriz = malloc(sizeof(t_trd *) * g.dimen.l);
	if (!g.matriz)
		return (0);
	while (++a < g.dimen.l)
		g.matriz[a] = malloc(sizeof(t_trd) * g.dimen.c + 1);
	g.pxls.off = offset_init(g.pxls.off);
	g.pxls = const_calc(g.dimen.c, g.dimen.l, g.pxls);
	calc_mesh(g.dimen, g.matriz, g.pxls);
	designer(g.dimen, g.matriz, g.img);
	mlx_put_image_to_window(g.mlx, g.mlx_win, g.img.img, 0, 0);
	controls(g);
	mlx_loop(g.mlx);
}
