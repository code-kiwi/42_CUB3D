/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/07/26 15:59:31 by codekiwi         ###   ########.fr       */
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
	if (player->weapon_state == WEAPON_STATE_HOLSTERING)
	{
		player->frame_update_delta += delta_time;
		if (player->frame_update_delta < PLAYER_WEAPON_ANIMATION_UPDATE)
			return ;
		player->frame_update_delta = 0;
		player->draw_offset.y += PLAYER_WEAPON_SWITCH_OFFSET;
		if (player->draw_offset.y >= weapon->curr_frame->height)
		{
			player->weapon_state = WEAPON_STATE_DRAWING;
			player->curr_weapon_index = player->next_weapon_index;
			player->curr_weapon = player->weapons[player->curr_weapon_index];
		}
	}
	if (player->weapon_state == WEAPON_STATE_DRAWING)
	{
		player->frame_update_delta += delta_time;
		if (player->frame_update_delta < PLAYER_WEAPON_ANIMATION_UPDATE)
			return ;
		player->frame_update_delta = 0;
		player->draw_offset.y -= PLAYER_WEAPON_SWITCH_OFFSET;
		if (player->draw_offset.y <= 0)
			player->weapon_state = WEAPON_STATE_IDLE;
	}
	if (player->weapon_state == WEAPON_STATE_USING)
	{
		player->frame_update_delta += delta_time;
		if (player->frame_update_delta < PLAYER_ANIMATION_UPDATE)
			return ;
		player->frame_update_delta = 0;
		update_weapon(weapon, game);
		if (player->curr_weapon->curr_frame == player->curr_weapon->frame_default)
			player->weapon_state = WEAPON_STATE_IDLE;
	}

}

void	update_player(t_game *game, float delta_time)
{
	update_look(&game->player, delta_time);
	update_position(&game->player, &game->map, delta_time, game->entities);
	update_player_weapon(&game->player, game->player.curr_weapon, game, \
		delta_time);
}
