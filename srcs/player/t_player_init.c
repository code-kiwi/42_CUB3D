/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:23:24 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/17 09:09:23 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d.h"
#include "player.h"
#include "map.h"

bool	t_player_init(t_player *player, t_map *map)
{
	size_t	index;

	if (player == NULL || map == NULL)
		return (false);
	player->fov_angle = FOV_ANGLE_DEFAULT;
	player->position = (t_vector){2.599842f, 3.982844f};
	player->orientation = 0;
	player->turn_direction = 0;
	player->move_speed[0] = 0.1;
	player->move_speed[1] = 0.05;
	player->move_speed[2] = 0.05;
	player->move_speed[3] = 0.05;
	player->rotation_speed = PI / 95;
	index = 0;
	while (index < 4)
	{
		player->is_walking[index] = false;
		index++;
	}
	return (true);
}
