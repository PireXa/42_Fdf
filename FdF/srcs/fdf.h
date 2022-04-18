/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:09:40 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/18 10:37:19 by fde-albe         ###   ########.fr       */
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
	int	x;
	int	y;
	int	z;
}			t_trd;

typedef struct dimensions {
	int	l;
	int	c;
}			t_dim;

typedef struct pix_coordinates {
	int	colx;
	int	liney;
	int	holdx;
	int	holdy;
	int		x_off;
	int		y_off;
	int		bargak;
	char	*map;
}			t_pxls;



typedef struct image {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_dim       dimen;
	t_trd       **matriz;
	t_pxls      pxls;
}			t_init_wind;



typedef struct draw_coor {
	float	x1;
	int	y1;
	int	x2;
	int	y2;
	int	a;
}			t_drw;

typedef struct coor_kingdm {
	float	s_rei;
	float	s_plebeu;
	int	x_ple;
	int	y_ple;
}			t_kng;

typedef struct counter {
	int	a;
	int	b;
	int	c;
	int	d;
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

void    ft_bzero(void *s, size_t len);

void    *ft_memset(void *dest, int val, size_t len);

int		ft_atoi(const char *str);

char	**ft_split(const char *s, char c);

t_pxls	const_calc(int columns, int lines, t_pxls pxls);

void	qual(t_data img);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	connector(t_drw crd, t_data img);

float	slope(float x1, int y1, int x2, int y2);

void	designer(t_dim dimen, t_trd **matriz, t_data img);

void	calc_mesh(t_dim dimen, char *map, t_trd **matriz, t_pxls pxls);

void	controls(t_init_wind g);

#endif
