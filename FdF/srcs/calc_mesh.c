/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:45:00 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 10:34:07 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pxl_y_corrector(t_dim dimen, int bargak, t_trd **matriz)
{
	int	s;
	int	t;

	s = -1;
	t = -1;
	while (++s < dimen.l)
	{
		while (++t < dimen.c)
			matriz[s][t].y -= matriz[s][t].z * bargak * 1.5;
		t = -1;
	}
}

void	calc_mesh2(t_dim dimen, int a, t_trd **m, t_pxls pxs)
{
	int		b;
	char	**hold;

	b = -1;
	hold = ft_split(pxs.map, 32);
	while (++b < dimen.c && hold[b] != NULL)
	{
		m[a][b].x = pxs.colx;
		m[a][b].y = pxs.liney;
		m[dimen.l - a - 1][b].z = ft_atoi(hold[b]) * pxs.off.z_off * pxs.off.r;
		m[dimen.l - a - 1][b].clr = color_reader(hold[b]);
		pxs.colx += pxs.bargak * 2;
		pxs.liney -= pxs.bargak;
	}
	free (hold);
}

void	calc_mesh(t_dim dimen, t_trd **matriz, t_pxls pxls)
{
	int		b;
	int		fd;
	int		a;

	a = dimen.l;
	b = -1;
	fd = open(pxls.map, O_RDWR);
	while (--a >= 0)
	{
		pxls.map = get_next_line(fd);
		calc_mesh2(dimen, a, matriz, pxls);
		pxls.holdx -= pxls.bargak * 2;
		pxls.holdy -= pxls.bargak;
		pxls.colx = pxls.holdx;
		pxls.liney = pxls.holdy;
		b = -1;
	}
	pxl_y_corrector(dimen, pxls.bargak, matriz);
	close (fd);
}
