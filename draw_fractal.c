/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:37:38 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/25 21:43:18 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	zoom(t_vars *vars)
{
	double	mouse_world_x;
	double	mouse_world_y;

	if (vars->zoom_stat == 0)
		return ;
	mouse_world_x = vars->args->scale * (vars->mouse_x - WEIGHT / 2);
	mouse_world_y = vars->args->scale * (vars->mouse_y - HEIGHT / 2);
	vars->dx += SCALE_FACTOR * mouse_world_x * (double)vars->zoom_stat;
	vars->dy += SCALE_FACTOR * mouse_world_y * (double)vars->zoom_stat;
	if (vars->zoom_stat == ZOOM_UP)
		vars->args->scale *= (1 - SCALE_FACTOR);
	else if (vars->zoom_stat == ZOOM_DOWN)
		vars->args->scale *= (1 + SCALE_FACTOR);
}

void	draw_loop(t_vars *vars)
{
	int	i;
	int	j;

	zoom(vars);
	i = 0;
	while (i < WEIGHT)
	{
		j = 0;
		while (j < HEIGHT)
		{
			vars->fractal_f(vars, vars->args, i, j);
			j++;
		}
		i++;
	}
	vars->zoom_stat = ZOOM_NONE;
}