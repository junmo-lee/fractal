/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:08:57 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/25 21:36:19 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	init(t_vars	*vars, t_args *args)
{
	ft_memset(vars, 0, sizeof(t_vars));
	vars->args = args;
	ft_memset(vars->args, 0, sizeof(t_args));
	vars->args->scale = 1;
	vars->args->color_ratio = 4;
	vars->args->trgb0 = 0x00FF0000;
	vars->args->color_ratio = 4;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WEIGHT, HEIGHT, "fractal");
	vars->img = mlx_new_image(vars->mlx, WEIGHT, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, \
		&(vars->bits_per_pixel), &(vars->line_length), &(vars->endian));
	return (0);
}
