/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/07/25 19:20:50 by codekiwi         ###   ########.fr       */
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

static void	update_player_weapon(
	t_player *player,
	t_weapon *weapon,
	t_game *game,
	float delta_time
)
{
	if (player->is_switching_weapon)
	{
		player->frame_update_delta2 += delta_time;
		if (player->frame_update_delta2 < PLAYER_ANIMATION_UPDATE)
			return ;
		if (player->is_holstering)
		{
			player->draw_offset.y += 10;
			if (player->draw_offset.y >= weapon->curr_frame->height)
			{
				player->is_holstering = false;
				player->curr_weapon_index = player->next_weapon_index;
				player->curr_weapon = player->weapons[player->curr_weapon_index];
			}
			return ;
		}
		player->draw_offset.y -= 10;
		if (player->draw_offset.y <= 0)
			player->is_switching_weapon = false;
		return ;
	}
	player->frame_update_delta += delta_time;
	if (player->frame_update_delta < PLAYER_ANIMATION_UPDATE)
		return ;
	update_weapon(weapon, game);
	player->frame_update_delta = 0;
}

void	update_player(t_game *game, float delta_time)
{
	update_look(&game->player, delta_time);
	update_position(&game->player, &game->map, delta_time, game->entities);
	update_player_weapon(&game->player, game->player.curr_weapon, game, \
		delta_time);
}
