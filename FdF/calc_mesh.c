/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:45:00 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/14 13:40:30 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_trd	**pxl_y_corrector(t_dim dimen, short bargak, t_trd **matriz)
{
	int	s;
	int	t;

	s = -1;
	t = -1;
	while (++s < dimen.l)
	{
		while (++t < dimen.c)
			matriz[s][t].y -= matriz[s][t].z * bargak * 1.5 / 10;
		t = -1;
	}
	return (matriz);
}

t_trd	**calc_mesh2(t_dim dimen, short a, t_trd **matriz, t_pxls pxls)
{
	int		b;
	char	**hold;

	b = -1;
	hold = ft_split(pxls.map, 32);
	while (++b < dimen.c)
	{
		matriz[a][b].x = pxls.colx;
		matriz[a][b].y = pxls.liney;
		matriz[dimen.l - a - 1][b].z = ft_atoi(hold[b]);
		pxls.colx += (pxls.bargak * 1.5 / 10);
		pxls.liney -= (pxls.bargak / 10);
	}
	return (matriz);
}

t_trd	**calc_mesh(t_dim dimen, char *map, t_trd **matriz, t_pxls pxls)
{
	int		b;
	int		fd;
	short	a;

	a = dimen.l;
	pxls.map = map;
	b = -1;
	fd = open(pxls.map, O_RDWR);
	while (--a >= 0)
	{
		pxls.map = get_next_line(fd);
		calc_mesh2(dimen, a, matriz, pxls);
		pxls.holdx -= (pxls.bargak * 1.5 / 10);
		pxls.holdy -= (pxls.bargak / 10);
		pxls.colx = pxls.holdx;
		pxls.liney = pxls.holdy;
		b = -1;
	}
	matriz = pxl_y_corrector(dimen, pxls.bargak, matriz);
	return (matriz);
}
