/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:23:24 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 13:30:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d.h"
#include "player.h"
#include "map.h"

bool	t_player_init(t_player *player, t_map *map)
{
	if (player == NULL || map == NULL)
		return (false);
	player->fov_angle = FOV_ANGLE_DEFAULT;
	player->position = (t_vector){1.5f, 1.5f};
	player->orientation = PI / 2;
	player->walk_dir = NONE;
	player->turn_direction = 0;
	player->move_speed = 0.01;
	player->rotation_speed = PI / 12;
	return (true);
}
