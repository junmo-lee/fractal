/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 21:49:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/26 17:34:50 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mandelbrot_point(t_vars *vars, t_args *args, int x, int y)
{
	t_pos	c;
	double	cx;
	double	cy;
	int		iter;

	cx = args->scale * (x - WEIGHT / 2) + vars->dx;
	cy = args->scale * (y - HEIGHT / 2) + vars->dy;
	c.x0 = args->center_x;
	c.y0 = args->center_y;
	iter = 0;
	while (iter < ITER_MAX)
	{
		c.x1 = c.x0 * c.x0 - c.y0 * c.y0 + cx;
		c.y1 = 2 * c.x0 * c.y0 + cy;
		if (c.x1 * c.x1 + c.y1 * c.y1 > args->div_val)
		{
			my_mlx_pixel_put(vars, x, y, \
				vars->colormap[PALETTE_SIZE * iter / ITER_MAX]);
			return ;
		}
		c.x0 = c.x1;
		c.y0 = c.y1;
		iter++;
	}
	my_mlx_pixel_put(vars, x, y, trgb(0, 0, 0, 0));
}
