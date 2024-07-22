/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/07/22 10:50:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"
#include "entities_bonus.h"

static void	update_look(t_player *player, float delta_time)
{
	if (player->rotation_speed != 0.0f)
	{
		player->orientation += player->rotation_speed * delta_time;
		player->rotation_speed = 0.0f;
	}
	if (player->orientation > 2 * PI)
		player->orientation -= 2 * PI;
	else if (player->orientation < 0)
		player->orientation += 2 * PI;
}

static void	update_position(t_player *player, t_map *map, float delta_time,
	t_list *entities)
{
	float			new_angle;
	t_vector		move;
	size_t			index;

	index = 0;
	while (index < 4)
	{
		if (player->is_walking[index] != false
			&& player->is_walking[(index + 2) % 4] == false)
		{
			new_angle = player->orientation + index * PI / 2;
			move.x = cos(new_angle) * player->move_speed[index] * delta_time;
			move.y = -sin(new_angle) * player->move_speed[index] * delta_time;
			move_entity(entities, &player->position, &move, map);
		}
		index++;
	}
}

void	update_player(t_player *player, t_map *map, float delta_time,
	t_list *entities)
{
	update_look(player, delta_time);
	update_position(player, map, delta_time, entities);
}
