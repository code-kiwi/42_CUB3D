/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:03:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/13 10:15:40 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>

void	init_params(t_param *param)
{
	param->fov = PI / 2;
	param->height = 920;
	param->width = 3;
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (!read_map(&game.map, argv[1]))
		return (EXIT_FAILURE);
	init_params(&game.param);
	game.player_rotation_rad = 7 * PI / 4;
	print_str_array(game.map.tiles);
	vector_init(&game.player_position, 1, 1);
	vector_print("position : ", &game.player_position);

	draw_walls(&game);

	free_array(game.map.tiles);
	free(game.map.lines_lengths);
	return (EXIT_SUCCESS);
}
