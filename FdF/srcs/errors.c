/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:55:35 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/22 17:24:11 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	file_exists(char *str)
{
	int	fd;
	fd = open(str, O_RDWR);
	if (fd == -1)
		return (1);
	return (0);
}

int	error_check(int ac, char *str)
{
	if (ac != 2)
	{
		ft_printf("\n\e[0;31mWRONG ARGUMENT NUMBER!\n\n");
		return (1);
	}
	if (ft_strchr(str, '.') == NULL)
	{
		ft_printf("\n\e[0;31mNO FILE EXTENSION\n\n");
		return (1);
	}
	if (ft_strncmp(ft_strchr(str, '.'), ".fdf\0", 5) != 0)
	{
		ft_printf("\n\e[0;31mFILE EXTENSION MUST BE .fdf!\n\n");
		return (1);
	}
	else if (file_exists(str))
	{
		ft_printf("\n\e[0;31mFILE DOESN'T EXIST!\n\n");
		return (1);
	}
	return (0);
}

int	ft_error(int check)
{
	if (check == -1)
	{
		ft_printf("MAP INVALID\n");
		ft_printf("Map has lines with different amount of columns\n");
		return (1);
	}
	return (0);
}
