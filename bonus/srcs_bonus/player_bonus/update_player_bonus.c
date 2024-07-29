/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/07/29 16:51:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"
#include "entities_bonus.h"

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
		if (player->is_walking[index] != false
			&& player->is_walking[(index + 2) % 4] == false)
		{
			new_angle = player->orientation.x + index * PI / 2;
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
	if (display->frame_curr == NULL)
		display->frame_curr = display->frames;
	display->frame_update_delta = 0;
}

void	update_player(t_player *player, t_map *map, float delta_time,
	t_list *entities)
{
	update_look(player, delta_time);
	update_position(player, map, delta_time, entities);
	update_display(&player->display, delta_time);
}
