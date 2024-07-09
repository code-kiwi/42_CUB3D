/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/07/09 14:09:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"
#include "entities_bonus.h"

static bool	is_moving_player(t_player *player)
{
	return (
		player != NULL
		&& (
			player->is_walking[0]
			|| player->is_walking[1]
			|| player->is_walking[2]
			|| player->is_walking[3]
		)
	);
}

static void	update_look(t_player *player, float delta_time)
{
	float	speed;

	speed = player->rotation_speed;
	if (is_moving_player(player))
		speed *= 0.8f;
	if (player->turn_direction[0] && !player->turn_direction[1])
		player->orientation += speed * delta_time;
	else if (player->turn_direction[1] && !player->turn_direction[0])
		player->orientation -= speed * delta_time;
	player->turn_direction[0] = false;
	player->turn_direction[1] = false;
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

static void	update_display(t_player_display *display, float delta_time)
{
	if (display == NULL || display->frame_curr == display->frames)
		return ;
	display->frame_update_delta += delta_time;
	if (display->frame_update_delta < PLAYER_ANIMATION_UPDATE)
		return ;
	display->frame_curr = display->frame_curr->next;
	display->frame_update_delta = 0;
}

void	update_player(t_player *player, t_map *map, float delta_time,
	t_list *entities)
{
	update_look(player, delta_time);
	update_position(player, map, delta_time, entities);
	update_display(&player->display, delta_time);
}
