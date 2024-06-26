/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:40:28 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/26 20:40:43 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

size_t	normlization(t_args *args, int iter)
{
	return (args->color_start + \
		(args->color_end - args->color_start) * (iter / (double)ITER_MAX));
}

int	read_colormap(int *colormap)
{
	int		fd;
	ssize_t	read_byte;

	fd = open(COLORMAP_DIR, O_RDONLY);
	if (fd == -1)
		return (0);
	read_byte = read(fd, colormap, PALETTE_SIZE * sizeof(int));
	if (read_byte != PALETTE_SIZE * 4)
		return (0);
	return (1);
}
