/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:35:47 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/21 22:04:14 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "libft/libft.h"
# include <math.h>
# include <mlx.h>

// 테스트용
# include <stdio.h> 

# define WEIGHT 1920
# define HEIGHT 1080

typedef struct s_args
{
	int		type;
	int		center_x;
	int		center_y;
	int		scale;
	int		r0;
	int		g0;
	int		b0;
	int		color_ratio;
}	t_args;

int	parsing(t_args *args, int argc, char *argv[]);

#endif