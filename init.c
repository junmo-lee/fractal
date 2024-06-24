/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:08:57 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/24 20:14:08 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	init(t_args	*args)
{
	ft_memset(args, 0, sizeof(t_args));
	args->scale = 1;
	args->color_ratio = 4;
	args->trgb0 = 0x00FF0000;
	args->color_ratio = 4;
	return (0);
}