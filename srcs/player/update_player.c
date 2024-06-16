/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/06/16 15:01:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

static void	update_look(t_player *player)
{
	if (player->turn_direction == -1)
		player->orientation += player->rotation_speed;
	else if (player->turn_direction == 1)
		player->orientation -= player->rotation_speed;
}

static void	update_position(t_player *player, t_map *map)
{
	float		new_angle;
	t_vector	save_position;

	if (player->walk_dir != NONE)
	{
		save_position = player->position;
		new_angle = player->orientation + player->walk_dir * PI / 2;
		player->position.x += cos(new_angle) * player->move_speed;
		player->position.y -= sin(new_angle) * player->move_speed;
		if (is_wall(&player->position, map))
			player->position = save_position;
	}
}

void	update_player(t_player *player, t_map *map)
{
	update_look(player);
	update_position(player, map);
}
