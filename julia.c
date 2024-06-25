/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:23:57 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/25 20:37:53 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

int	zoom(t_vars *vars)
{
	if (vars->zoom_stat == 0)
		return (0);
	printf("zoom run! : ");
	vars->dx += vars->args->scale / 1000.0 * SCALE_FACTOR * (vars->mouse_x - WEIGHT / 2);
	vars->dy += vars->args->scale / 1000.0 * SCALE_FACTOR * (vars->mouse_y - HEIGHT / 2);
	//확대(scale 이 감소하는 방향)
	if (vars->zoom_stat == ZOOM_UP)
		vars->args->scale *= (1 - SCALE_FACTOR);
	//축소(scale 이 증가하는 방향) 
	else if (vars->zoom_stat == ZOOM_DOWN)
		vars->args->scale *= (1 + SCALE_FACTOR);
	printf("%lf %lf\n ", vars->dx, vars->dy);
	return (0);
}

int	julia_point(t_vars *vars, t_args *args, int screen_x, int screen_y)
{
	t_pos	c;

	// to screen x to world x
	// zoom 변수에서 scale 이 변경된 이후 
	c.x0 = args->scale / 1000.0 * (screen_x - WEIGHT / 2) + vars->dx;
	c.y0 = args->scale / 1000.0 * (screen_y - HEIGHT / 2) + vars->dy;
 
 	double cx = args->center_x / 10000.0;
	double cy = args->center_y / 10000.0;

	for(int iter=0;iter<ITER_MAX;iter++)
	{
		c.x1 = c.x0 * c.x0 - c.y0 * c.y0 + cx;
		c.y1 = 2 * c.x0 * c.y0 + cy;
		if (c.x1 * c.x1 + c.y1 * c.y1 > args->color_ratio)
		{
			my_mlx_pixel_put(vars, screen_x, screen_y, trgb(0, iter / 3, iter/100, iter/5));
			return (0);
		}
		c.x0 = c.x1;
		c.y0 = c.y1;
	}
	return (0);
}

int	julia_loop(t_vars *vars, t_args *args)
{
	// 값 정규화?
	zoom(vars);

	for(int i=1;i<WEIGHT;i++)
	{
		for (int j=1;j<HEIGHT;j++)
			julia_point(vars, args, i, j);
	}
	vars->zoom_stat = 0;
	return (1);
}