/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:20:28 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/21 22:06:39 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	print_help(void)
{
	write(STDOUT_FILENO, "----read me!----\n", 18);
	write(STDOUT_FILENO, "1. Type of fractal\n", 21);
	write(STDOUT_FILENO, " 0 : 쥘리아 집합\n", 23);
	write(STDOUT_FILENO, " 1 : 망델브로 집합 집합\n", 33);
	write(STDOUT_FILENO, "2 3. start pos x, y\n", 21);
	write(STDOUT_FILENO, "4 start scale\n", 15);
	write(STDOUT_FILENO, "5 6 7. r0, g0, b0(0~255)\n", 26);
	write(STDOUT_FILENO, "8. color ratio\n", 16);
	write(STDOUT_FILENO, "RGB 제외 인자들은 양수 int로, 소수점 아래 절삭\n", 64);
	write(STDOUT_FILENO, "없는 인자들은 기본값으로 설정\n", 44);
	write(STDOUT_FILENO, "기본값 : 0 0 0 10 255 255 255 10\n", 37);
	write(STDOUT_FILENO, "이후 인자들은 무시\n", 28);
}

int	parsing(t_args *args, int argc, char *argv[])
{
	args->g0 = 0;
	argc++;
	argv++;
	print_help();
	return (0);
}