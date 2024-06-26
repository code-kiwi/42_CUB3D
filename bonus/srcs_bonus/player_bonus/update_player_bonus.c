/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/06/27 17:28:23 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"

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
	float		new_angle;
	t_vector	save_position;
	size_t		index;

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
			if (!is_in_bounds(&player->position, map)
				|| is_character(&player->position, map, ID_WALL)
				|| is_character(&player->position, map, ID_DOOR_CLOSED))
			{
				player->position = save_position;
			}
		}
		index++;
	}
}

static void	update_display(t_player_display *display, float delta_time)
{
	if (
		display == NULL
		|| display->frame_curr == display->frames
	)
		return ;
	display->frame_update_delta += delta_time;
	if (display->frame_update_delta < PLAYER_ANIMATION_UPDATE)
		return ;
	display->frame_curr = display->frame_curr->next;
	display->frame_update_delta = 0;
}

void	update_player(t_player *player, t_map *map, float delta_time)
{
	update_look(player, delta_time);
	update_position(player, map, delta_time);
	update_display(&player->display, delta_time);
}
