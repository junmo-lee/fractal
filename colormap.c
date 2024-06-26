/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colormap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:40:28 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/26 17:35:28 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>

void print_color_map(int *color_map) {
    for (int i = 0; i < PALETTE_SIZE; ++i) {
        printf("Color %d: %d\n", i, color_map[i]);
    }
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
		printf("error!");
	else
		print_color_map(colormap);
	return (1);
}