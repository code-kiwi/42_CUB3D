/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/08/26 17:40:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"
#include "entities_bonus.h"

static bool	is_walking(t_player *player)
{
	return (
		(player->walk_direction[FRONT] && !player->walk_direction[BACK])
		|| (player->walk_direction[BACK] && !player->walk_direction[FRONT])
		|| (player->walk_direction[LEFT] && !player->walk_direction[RIGHT])
		|| (player->walk_direction[RIGHT] && !player->walk_direction[LEFT])
	);
}

static void	update_look(t_player *player, float delta_time)
{
	float	new_y_rot;

	if (player->rotation_speed.x != 0.0f)
	{
		player->orientation.x += player->rotation_speed.x * delta_time;
		player->rotation_speed.x = 0.0f;
	}
	if (player->orientation.x > 2 * PI)
		player->orientation.x -= 2 * PI;
	else if (player->orientation.x < 0)
		player->orientation.x += 2 * PI;
	new_y_rot = player->orientation.y + player->rotation_speed.y * delta_time;
	if (player->rotation_speed.y != 0.0f
		&& abs((int)new_y_rot) < MAX_Y_ROTATION_RATIO * WIN_HEIGHT)
	{
		player->orientation.y = new_y_rot;
		player->rotation_speed.y = 0.0f;
	}
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
		if (player->walk_direction[index] != false
			&& player->walk_direction[(index + 2) % 4] == false)
		{
			new_angle = player->orientation.x + index * PI / 2;
			move.x = cos(new_angle) * player->move_speed[index] * delta_time;
			move.y = -sin(new_angle) * player->move_speed[index] * delta_time;
			move_player(entities, &player->position, &move, map);
		}
		index++;
	}
}

void	update_player(t_game *game, float delta_time)
{
	if (game == NULL)
		return ;
	game->player.is_walking = is_walking(&game->player);
	update_look(&game->player, delta_time);
	update_position(&game->player, &game->map, delta_time, game->entities);
	update_player_weapon(&game->player.weapon_info, game->player.is_walking, \
		game, delta_time);
}
