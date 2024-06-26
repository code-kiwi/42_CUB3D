/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/06/27 14:12:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"

static void	update_look(t_player *player, float delta_time)
{
	if (player->turn_direction[0] && !player->turn_direction[1])
		player->orientation += player->rotation_speed * delta_time;
	else if (player->turn_direction[1] && !player->turn_direction[0])
		player->orientation -= player->rotation_speed * delta_time;
	if (player->orientation > 2 * PI)
		player->orientation -= 2 * PI;
	else if (player->orientation < 0)
		player->orientation += 2 * PI;
}

static void	update_position(t_player *player, t_map *map, float delta_time)
{
	float			new_angle;
	t_vector		save_position;
	size_t			index;
	t_mlx_coords	coords;

	index = 0;
	while (index < 4)
	{
		if (player->is_walking[index] != false
			&& player->is_walking[(index + 2) % 4] == false)
		{
			save_position = player->position;
			new_angle = player->orientation + index * PI / 2;
			player->position.x += cos(new_angle) * player->move_speed[index] \
				* delta_time;
			player->position.y -= sin(new_angle) * player->move_speed[index] \
				* delta_time;
			coords.x = player->position.x;
			coords.y = player->position.y;
			if (!is_walkable(map, &coords))
				player->position = save_position;
		}
		index++;
	}
}

void	update_player(t_player *player, t_map *map, float delta_time)
{
	update_look(player, delta_time);
	update_position(player, map, delta_time);
}
