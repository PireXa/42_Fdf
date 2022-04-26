/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:55:35 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/26 10:47:37 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	file_exists(char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDWR);
	line = get_next_line(fd);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	if (!line)
	{
		close(fd);
		return (1);
	}
	free(line);
	close(fd);
	return (0);
}

void	error_check(int ac, char *str)
{
	if (ac != 2)
	{
		ft_printf("\n\e[0;31mWRONG ARGUMENT NUMBER!\n\n");
		exit (1);
	}
	if (ft_strchr(str, '.') == NULL)
	{
		ft_printf("\n\e[0;31mNO FILE EXTENSION\n\n");
		exit (1);
	}
	if (ft_strncmp(ft_strchr(str, '.'), ".fdf\0", 5) != 0)
	{
		ft_printf("\n\e[0;31mFILE EXTENSION MUST BE .fdf!\n\n");
		exit (1);
	}
	else if (file_exists(str))
	{
		ft_printf("\n\e[0;31mFILE DOESN'T EXIST!\n\n");
		exit (1);
	}
}
