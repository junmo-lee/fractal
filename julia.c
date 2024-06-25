/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:23:57 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/25 22:21:03 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia_point(t_vars *vars, t_args *args, int screen_x, int screen_y)
{
	t_pos	c;

	c.x0 = args->scale * (screen_x - WEIGHT / 2) + vars->dx;
	c.y0 = args->scale * (screen_y - HEIGHT / 2) + vars->dy;

	for(int iter=0;iter<ITER_MAX;iter++)
	{
		c.x1 = c.x0 * c.x0 - c.y0 * c.y0 + args->center_x;
		c.y1 = 2 * c.x0 * c.y0 + args->center_y;
		if (c.x1 * c.x1 + c.y1 * c.y1 > args->color_ratio)
		{
			my_mlx_pixel_put(vars, screen_x, screen_y, \
				trgb(0, iter / 3, iter / 100, iter / 5));
			return ;
		}
		c.x0 = c.x1;
		c.y0 = c.y1;
	}
	my_mlx_pixel_put(vars, x, y, trgb(0, 0, 0, 0));
}
