/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:23:57 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/25 15:54:38 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void update_center_with_mouse(t_args *args, int mouse_x, int mouse_y)
{
    double dx = (mouse_x - WEIGHT / 2) / 1000.0;
    double dy = (mouse_y - HEIGHT / 2) / 1000.0;
    args->center_x += dx * args->scale;
    args->center_y += dy * args->scale;
}

int	julia_point(t_vars *vars, t_args *args, int x, int y)
{
	t_pos	c;

	//c.x0 = args->scale / 1000.0 * (x - WEIGHT / 2 + vars->test_val);
	double dx = (vars->mouse_x - WEIGHT / 2);
    double dy = (vars->mouse_y - HEIGHT / 2);
	c.x0 = args->scale / 1000.0 * (x - WEIGHT / 2 - dx);
	c.y0 = args->scale / 1000.0 * (y - HEIGHT / 2 - dy);

	// -7453 1314 / 10000.0 인데 이값을 바꿔도 되나?
	double cx = args->center_x / 10000.0;
	double cy = args->center_y / 10000.0;

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

int	julia_loop(t_vars *vars, t_args *args)
{
	//update_center_with_mouse(args, vars->mouse_x, vars->mouse_y);

	for(int i=1;i<WEIGHT;i++)
	{
		for (int j=1;j<HEIGHT;j++)
			julia_point(vars, args, i, j);
	}
}