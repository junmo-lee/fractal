/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:40:28 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/28 16:28:24 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_bonus.h"

int	trgb(t_args *args, int i, unsigned char t)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = args->color_start + i / 2;
	g = args->color_start + i / 3;
	b = args->color_start + i;
	return (t << 24 | r << 16 | g << 8 | b);
}

int	make_colormap_log(t_args *args, int *color_map)
{
	int		i;
	double	n;

	if (ITER_MAX == 0)
		return (1);
	n = (double)(args->color_end - args->color_start) / log(ITER_MAX);
	color_map[0] = trgb(args, 0, RGB_T);
	i = 1;
	while (i < ITER_MAX)
	{
		color_map[i] = trgb(args, log(i) * n, RGB_T);
		i++;
	}
	return (0);
}

int	make_colormap_liner(t_args *args, int *color_map)
{
	int		i;
	int		n;

	if (ITER_MAX == 0)
		return (1);
	n = args->color_end - args->color_start;
	color_map[0] = trgb(args, 0, RGB_T);
	i = 1;
	while (i < ITER_MAX)
	{
		color_map[i] = trgb(args, n * i / ITER_MAX, RGB_T);
		i++;
	}
	return (0);
}
