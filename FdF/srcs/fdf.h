/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:09:40 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/14 18:47:10 by fde-albe         ###   ########.fr       */
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

# define BUFFER_SIZE 10
# define WIND_H 1080
# define WIND_W 1920
# define MANGENTA 0x00FF00FF

typedef struct s_data {
	void	*img;
	char	*addr;
	int		p;
	int		lgt;
	int		e;
}			t_data;

typedef struct coordinates {
	short	x;
	short	y;
	short	z;
}			t_trd;

typedef struct dimensions {
	short	l;
	short	c;
}			t_dim;

typedef struct pix_coordinates {
	short	colx;
	short	liney;
	short	holdx;
	short	holdy;
	short	bargak;
	char	*map;
}			t_pxls;

typedef struct image {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}			t_init_wind;

typedef struct draw_coor {
	float	x1;
	short	y1;
	short	x2;
	short	y2;
	short	a;
}			t_drw;

typedef struct coor_kingdm {
	float	s_rei;
	float	s_plebeu;
	short	x_ple;
	short	y_ple;
}			t_kng;

typedef struct counter {
	short	a;
	short	b;
	short	c;
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

int		ft_atoi(const char *str);

char	**ft_split(const char *s, char c);

t_pxls	const_calc(short columns, short lines, t_pxls pxls);

void	qual(t_data img);

void	my_mlx_pixel_put(t_data *data, short x, short y, int color);

void	connector(t_drw crd, t_data img);

float	slope(float x1, short y1, short x2, short y2);

void	designer(t_dim dimen, t_trd **matriz, t_data img);

t_trd	**calc_mesh(t_dim dimen, char *map, t_trd **matriz, t_pxls pxls);

void	controls(t_init_wind g);

#endif
