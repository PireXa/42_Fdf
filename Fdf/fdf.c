/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:09:52 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/11 10:43:31 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"
#include <fcntl.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	sovai {
	int		x;
	int		y;
	int		z;
}				coor;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		fd;
	char	*line;
	int		columns = 0;
	int		lines = 0;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDWR);
	while ((line = get_next_line(fd)))
    {
		columns = valuescount(line);
		lines++;
        free(line);
	}
	close(fd);
	printf("lines: %d\n", lines);
	printf("columns: %d\n***************************\n", columns);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Please so vai");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	
	int Bargakṣētra = 0;
	
	if (columns >= lines)
		Bargakṣētra = columns;
	else
		Bargakṣētra = lines;

	if (Bargakṣētra <= 20)
		Bargakṣētra = 17;
	else if (Bargakṣētra <= 50)
		Bargakṣētra = 9;
	else if (Bargakṣētra <= 100)
		Bargakṣētra = 7;
	else
		Bargakṣētra = 1;

//Build Mesh Base
	coor	matriz[lines + 1][columns + 1];	

	int colx = 960;
	int liney = 1070;
	int holdx = colx;
	int holdy = liney;

	for (int a = lines; a > 0; a--) //a = lines index
	{
		for (int b = 0; b < columns; b++) //b = columns index
		{
			matriz[a][b].x = colx;
			matriz[a][b].y = liney;
//			printf("x = %d\ny = %d\n", matriz[a][b].x, matriz[a][b].y);
//			printf("a: %d\nb: %d\n", a, b);
//			printf("\n***************\n");
			colx += (Bargakṣētra * 3);
			liney -= (Bargakṣētra * 2);
		}
		printf("x = %d\ny = %d\n", matriz[a][0].x, matriz[a][0].y);
		printf("a: %d\n", a);
		printf("\n***************\n");
		holdx -= (Bargakṣētra * 3);
		holdy -= (Bargakṣētra * 2);
		colx = holdx;
		liney = holdy;
	}
	printf("Bargakṣētra: %d\n", Bargakṣētra);
	printf("lines: %d\n columns: %d\n", lines, columns);
/*
	int counterboy;
	for (int a = lines; a > 0; a--)
	{
		for (int b = 0; b < columns; b++)
		{
			printf("counterboy: %d\n", counterboy);
			counterboy++;
			for (int c = 0; c < 5; c++)
			{
				printf("printyboy\n");
				my_mlx_pixel_put(&img, matriz[a][b].x, matriz[a][b].y, 0x00FFFF00);
				my_mlx_pixel_put(&img, matriz[a][b].x, matriz[a][b].y + 1, 0x00FFFF00);
				my_mlx_pixel_put(&img, matriz[a][b].x, matriz[a][b].y + 2, 0x00FFFF00);
				my_mlx_pixel_put(&img, matriz[a][b].x, matriz[a][b].y + 3, 0x00FFFF00);
				my_mlx_pixel_put(&img, matriz[a][b].x, matriz[a][b].y + 4, 0x00FFFF00);
			}
		}
	}
*/
	
//Draw Lines
	int x = 960;
	int y = 1070;
	int xstart = x;
	int ystart = y;
	
	int ncolumns = columns - 1;
	int i = Bargakṣētra * ncolumns;
	int nlines = lines - 1;
	
	while (lines)
	{
		x = xstart;
		y = ystart;
		i = Bargakṣētra * ncolumns;

		while (i)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF00FF);
			y--;
			for (int b = 0; b < 2; b++)
			{
				for (int a = 0; a < 2; a++)
					my_mlx_pixel_put(&img, x++, y, 0x00FF00FF);
				x++;
				y--;
				b++;
			}
			i--;
		}
		xstart -= (Bargakṣētra * 3);
		ystart -= (Bargakṣētra * 2);
		lines--;
	}
//Draw Columns
	x = 960;
	y = 1070;
	xstart = x;
	ystart = y;

	int e = Bargakṣētra * nlines;

	while (columns)
	{
		x = xstart;
		y = ystart;
		e = Bargakṣētra * nlines;
		while (e)
		{
			my_mlx_pixel_put(&img, x, y, 0x00FF00FF);
			y--;
			for (int b = 0; b < 2; b++)
			{
				for (int a = 0; a < 2; a++)
					my_mlx_pixel_put(&img, x--, y, 0x00FF00FF);
				x--;
				y--;
				b++;
			}
			e--;
		}
		xstart += (Bargakṣētra * 3);
		ystart -= (Bargakṣētra * 2);
		columns--;
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

}
