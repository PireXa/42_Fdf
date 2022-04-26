/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:09:40 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/26 10:44:13 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <ctype.h>
# include "ft_printf.h"

# define BUFFER_SIZE 10
# define WIND_H 1080
# define WIND_W 1920
# define MANGENTA 0x00FF00FF

typedef struct s_data {
	void	*img;
	char	*a;
	int		p;
	int		l;
	int		e;
	int		clr;
}			t_data;

typedef struct coordinates {
	int		x;
	int		y;
	int		z;
	int		clr;
}			t_trd;

typedef struct dimensions {
	int		l;
	int		c;
}			t_dim;

typedef struct init_off {
	int		x_off;
	int		y_off;
	int		z_off;
	int		r;
	int		zoom;
}			t_off;

typedef struct pix_coordinates {
	int		colx;
	int		liney;
	int		holdx;
	int		holdy;
	int		bargak;
	char	*map;
	t_off	off;
}			t_pxls;

typedef struct draw_coor {
	float	x1;
	int		y1;
	int		x2;
	int		y2;
	int		a;
}			t_drw;

typedef struct image {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_dim	dimen;
	t_trd	**matriz;
	t_pxls	pxls;
}			t_fdf;

typedef struct coor_kingdm {
	float	s_rei;
	float	s_plebeu;
	int		x_ple;
	int		y_ple;
}			t_kng;

typedef struct counter {
	int		a;
	int		b;
	int		c;
	int		d;
}			t_ctr;

char	*ft_strchr(const char *s, int c);

char	*ft_exstrchr(char *s);

size_t	ft_strlen(const char *str);

char	*ft_strnldup(char *s1);

char	*ft_strjoin(char *s1, char *s2);

char	*ft_strdup(const char *s1);

char	*get_next_line(int fd);

size_t	ft_strlcpy(char *dst, char *src, size_t size);

int		valuescount(char *s);

void	ft_bzero(void *s, size_t len);

void	*ft_memset(void *dest, int val, size_t len);

int		ft_atoi(const char *str);

char	**ft_split(const char *s, char c);

t_pxls	const_calc(int columns, int lines, t_pxls pxls);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	connector(t_drw crd, t_data img);

void	designer(t_dim dimen, t_trd **matriz, t_data img);

void	calc_mesh(t_dim diment, t_trd **matriz, t_pxls pxls);

void	controls(t_fdf *g);

int		ft_isspace(int c);

void	move_model(int key, t_fdf *g);

void	zoom(int key, t_fdf *g);

void	reset_img(t_fdf *g);

void	draw_model(t_fdf *g);

void	increase_z(int key, t_fdf *g);

int		color_reader(char *s);

void	up_designer(t_fdf *g);

t_off	offset_init(t_off off);

t_fdf	*grf_initializer(void);

void	base_mesh(int key, t_fdf *g);

int		ft_printf(const char *str, ...);

int		ft_isdigit(int str);

void	error_check(int ac, char *str);

int		ft_error(int check);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		color_cmp(int a, int b);

t_dim	dim_definer(char *map);

t_trd	**allocate_matriz(t_dim dimen);

#endif
