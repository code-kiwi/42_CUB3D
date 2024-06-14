/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:03:08 by brappo            #+#    #+#             */
/*   Updated: 2024/06/14 09:23:09 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d.h"

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
	{
		printf("error reading map");
		return (EXIT_FAILURE);
	}
	print_str_array(game.map.textures, MAP_NB_IDS);
	init_params(&game.param);
	game.player_rotation_rad = 7 * PI / 4;
	print_str_array(game.map.tiles, game.map.lines_count);
	t_vector_init(&game.player_position, 1, 1);
	t_vector_print("position : ", &game.player_position);
	draw_walls(&game);
	free_array(game.map.tiles, game.map.lines_count, true);
	free_array(game.map.textures, MAP_NB_IDS, false);
	free(game.map.lines_lengths);
	return (EXIT_SUCCESS);
}
