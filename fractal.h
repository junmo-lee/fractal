/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:35:47 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/27 15:38:16 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h> 

# define WEIGHT 1080
# define HEIGHT 720

# define ITER_MAX 1000

# define ZOOM_UP 1
# define ZOOM_DOWN -1
# define ZOOM_NONE 0

# define KEY_X_UP 1
# define KEY_X_DOWN 2
# define KEY_Y_UP 3
# define KEY_Y_DOWN 4
# define KEY_MOVE_NONE 0
# define KEY_OFFSET 100

# define SCALE_FACTOR 0.25
# define ARGS_DIV 10000.0

# define COLORMAP_DIR "viridis_color_map.bin"
# define PALETTE_SIZE 256
# define WHITE_TRGB 0x00FFFFFF
# define BLACK_TRGB 0x00000000

typedef struct s_pos
{
	double	x0;
	double	y0;
	double	x1;
	double	y1;
}	t_pos;

typedef struct s_args
{
	int		type;
	double	cx;
	double	cy;
	double	scale;
	double	threshold;
	int		color_start;
	int		color_end;
}	t_args;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		mouse_x;
	int		mouse_y;
	int		zoom_stat;
	int		key_move;
	double	dx;
	double	dy;
	void	(*fractal_f)(struct s_vars*, struct s_args*, int, int);
	int		*color_map;
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
	KCODE_ESC = 53,
	KCODE_LEFT_ARROW = 123,
	KCODE_RIGHT_ARROW = 124,
	KCODE_DOWN_ARROW = 125,
	KCODE_UP_ARROW = 126
}	t_keycode;

typedef enum e_mousecode
{
	MCODE_LCLICK = 1,
	MCODE_RCLICK = 2,
	MCODE_MCLICK = 3,
	MCODE_SCROLLUP = 4,
	MCODE_SCROLLDOWN = 5
}	t_mousecode;


int		init(t_vars	*vars, t_args *args);
void	error_exit(t_vars *vars);

int		parsing(t_args *args, int argc, char *argv[]);
int		parsing2(t_args *args, int argc, char *argv[]);

int		args_config(t_vars *args);
size_t	normlization(t_args *args, int iter);
int		read_colormap(int *colormap);

int		atoi_check_num(const char *str, int *target);
int		atoi_double_check_num(const char *str, double *target);

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);

void	julia_point(t_vars *vars, t_args *args, int screen_x, int screen_y);
void	mandelbrot_point(t_vars *vars, t_args *args, int x, int y);
void	burning_ship_point(t_vars *vars, t_args *args, int x, int y);

void	draw_loop(t_vars *vars);
void	center_move(t_vars *vars);
void	zoom(t_vars *vars);


#endif