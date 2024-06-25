/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:49:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/25 22:20:33 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot_point(t_vars *vars, t_args *args, int x, int y)
{
	t_pos	c;

	double cx;
	double cy;

	cx = args->scale * (x - WEIGHT / 2) + vars->dx;
	cy = args->scale * (y - HEIGHT / 2) + vars->dy;

	c.x0 = args->center_x;
	c.y0 = args->center_y;

	for(int iter=0;iter<ITER_MAX;iter++)
	{
		c.x1 = c.x0 * c.x0 - c.y0 * c.y0 + cx;
		c.y1 = 2 * c.x0 * c.y0 + cy;
		if (c.x1 * c.x1 + c.y1 * c.y1 > args->color_ratio)
		{
			my_mlx_pixel_put(vars, x, y, trgb(0, iter % 10, iter % 210, iter / 5));
			return ;
		}
		c.x0 = c.x1;
		c.y0 = c.y1;
	}
	my_mlx_pixel_put(vars, x, y, trgb(0, 0, 0, 0));
}
