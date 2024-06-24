/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:35:47 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/24 21:55:26 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <stdbool.h>

# define WEIGHT 1080
# define HEIGHT 720
# define ITER_MAX 100

typedef struct s_args
{
	int		type;
	int		center_x;
	int		center_y;
	double		scale;
	int		trgb0;
	double		color_ratio;
}	t_args;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		iter;
	t_args	*args;
}	t_vars;

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}	t_event;

typedef enum e_keycode
{
	KCODE_ESC = 53
}	t_keycode;

typedef enum e_mousecode
{
	MCODE_LCLICK = 1,
	MCODE_RCLICK = 2,
	MCODE_MCLICK = 3,
	MCODE_SCROLLUP = 4,
	MCODE_SCROLLDOWN = 5
}	t_mousecode;


typedef struct s_pos
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
}	t_pos;


int	init(t_args	*args);

int	parsing(t_args *args, int argc, char *argv[]);
int	parsing2(t_args *args, int argc, char *argv[]);
int	atoi_check_num(const char *str, int *target);

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int	trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);

int	julia_loop(t_vars *vars, t_args *args);
int	mandelbrot_loop(t_vars *vars, t_args *args);

#endif