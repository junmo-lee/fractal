/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:20:28 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/24 20:43:22 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <stdio.h>


int	print_help(void)
{
	write(STDOUT_FILENO, "----read me!----\n", 18);
	write(STDOUT_FILENO, "1. Type of fractal\n", 20);
	write(STDOUT_FILENO, " 0 : 쥘리아 집합\n", 23);
	write(STDOUT_FILENO, " 1 : 망델브로 집합 집합\n", 33);
	write(STDOUT_FILENO, "2 3. start pos x, y\n", 21);
	write(STDOUT_FILENO, "4 start scale\n", 15);
	write(STDOUT_FILENO, "5 trgb\n", 8);
	write(STDOUT_FILENO, "6. color ratio\n", 16);
	write(STDOUT_FILENO, "RGB 제외 인자들은 양수 int로, 소수점 아래 절삭\n", 64);
	write(STDOUT_FILENO, "없는 인자들은 기본값으로 설정\n", 44);
	write(STDOUT_FILENO, "기본값 : 0 0 0 10 0 0 0 10\n", 31);
	write(STDOUT_FILENO, "이후 인자들은 무시\n", 28);
	return (1);
}

int	parsing(t_args *args, int argc, char *argv[])
{
	int	is_num;
	int	num;

	is_num = 0;
	if (argc == 1)
		return (print_help());
	is_num = atoi_check_num(argv[1], &(args->type));
	if (is_num == 0 || 0 > args->type || args->type > 2)
		return (print_help());
	if (argc > 2)
		if (atoi_check_num(argv[2], &(args->center_x)) == 0)
			return (print_help());
	if (argc > 3)
		if (atoi_check_num(argv[3], &args->center_y) == 0)
			return (print_help());
	if (argc > 4)
	{

		if (atoi_check_num(argv[4], &num) == 0)
			return (print_help());
		args->scale = num;	
	}
	if (argc > 5)
		if (atoi_check_num(argv[5], &args->trgb0) == 0)
			return (print_help());
	if (argc > 6)

	{

		if (atoi_check_num(argv[6], &num) == 0)
			return (print_help());
		args->color_ratio = num;
	}
	return (0);
}
