/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:27:54 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 11:38:33 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	closex(void *param)
{
	(void)param;
	exit(0);
}

int	user_hook(int a, void *param)
{
	t_fdf	*g;

	g = (t_fdf *)param;
	if (a == 53)
	{
		mlx_destroy_window(g->mlx, g->mlx_win);
		exit(0);
	}
	if (a == 123 || a == 124 || a == 125 || a == 126)
		move_model(a, g);
	else if (a == 6 || a == 7)
		zoom(a, g);
	else if (a == 34 || a == 37)
		increase_z(a, g);
	else if (a == 32)
		up_designer(g);
	else if (a == 11 || a == 45)
		base_mesh(a, g);
	return (0);
}

void	controls(t_fdf g)
{
	mlx_hook(g.mlx_win, 2, 0, user_hook, &g);
	mlx_hook(g.mlx_win, 17, 0, closex, &g);
}
