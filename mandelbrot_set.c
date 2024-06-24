/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:49:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/24 21:54:17 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot_point(t_vars *vars, t_args *args, int x, int y)
{
	t_pos	c;

	double cx = args->scale * (x-WEIGHT / 2) / 1000.0;
	double cy = args->scale * (y-HEIGHT / 2) / 1000.0;
	// c.x0 = (double)x / WEIGHT * args->scale;
	// c.y0 = (double)y / HEIGHT * args->scale;

	c.x0 = args->center_x / 10000.0;
	c.y0 = args->center_y / 10000.0;
	// double cx = 0.4;
	// double cy = 0.4;

	for(int iter=0;iter<ITER_MAX;iter++)
	{
		c.x1 = c.x0 * c.x0 - c.y0 * c.y0 + cx;
		c.y1 = 2 * c.x0 * c.y0 + cy;
		if (c.x1 * c.x1 + c.y1 * c.y1 > args->color_ratio)
		{
			my_mlx_pixel_put(vars, x, y, trgb(0, iter%64, 0, (255 - iter%255)/5));
			return (0);
		}
		c.x0 = c.x1;
		c.y0 = c.y1;
	}
}

int	mandelbrot_loop(t_vars *vars, t_args *args)
{
	for(int i=1;i<WEIGHT;i++)
	{
		for (int j=1;j<HEIGHT;j++)
			mandelbrot_point(vars, args, i, j);
	}
}