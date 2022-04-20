/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_handlers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:02:25 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/20 16:08:20 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	increase_z(int key, t_init_wind *g)
{
	reset_img(g);
	if (key == 34)
		g->pxls.off.z_off += 1;
	else if (key == 37)
		g->pxls.off.z_off -= 1;
	draw_model(g);
}
