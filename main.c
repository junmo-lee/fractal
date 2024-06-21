/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:33:24 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/21 22:04:26 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	main(int argc, char *argv[])
{
	t_args	args;
	void	*mlx;
	void	*mlx_win;

	parsing(&args, argc, argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WEIGHT, HEIGHT, "hello world");
	mlx_loop(mlx);
}