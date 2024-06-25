/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:33:24 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/25 20:37:01 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

int	trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}


void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KCODE_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

// int	mouse_up(int butten, t_vars *vars)
// {
// 	if (butten == MCODE_SCROLLUP)
// 		printf("scroll up _ up!\n");
// 	printf("mouse up!\n");
// 	return (0);
// }

int	mouse_down(int butten, int x, int y, t_vars *vars)
{
	vars->mouse_x = x;
	vars->mouse_y = y;
	if (butten == MCODE_SCROLLUP)
	{
		vars->zoom_stat = ZOOM_UP;
		printf("scroll up! : ");
	}
	else if (butten == MCODE_SCROLLDOWN)
	{
		vars->zoom_stat = ZOOM_DOWN;
		printf("scroll down! : %lf\n",(vars->args)->scale);
	}
	else
		vars->zoom_stat = 0;
	printf("%lf x : %d y : %d\n",(vars->args)->scale, x, y);
	julia_loop(vars, (vars->args));
	//mandelbrot_loop(vars, (vars->args));
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int exit_hook()
{
	exit(0);
}


int	main(int argc, char *argv[])
{
	t_args	args;
	t_vars	vars;

	init(&args);
	vars.args = &args;
	if (parsing(&args, argc, argv))
		return (1);
	vars.mlx = mlx_init();
	// 이미지 객체 생성
	vars.win = mlx_new_window(vars.mlx, WEIGHT, HEIGHT, "hello world");
	vars.img = mlx_new_image(vars.mlx, WEIGHT, HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, \
		&(vars.bits_per_pixel), &(vars.line_length), &(vars.endian));
	vars.zoom_stat = 0;
	julia_loop(&vars, &args);
	printf("%d %lf\n",args.trgb0, args.color_ratio);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);

	//mlx_hook(vars.win, ON_MOUSEUP, 0, mouse_up, &vars);
	mlx_hook(vars.win, ON_MOUSEDOWN, 0, mouse_down, &vars);
	mlx_hook(vars.win, ON_KEYUP, 0, key_press, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, exit_hook, 0); // close button press event
	mlx_loop(vars.mlx);

}