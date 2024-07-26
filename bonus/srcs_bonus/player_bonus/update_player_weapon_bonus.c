/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_weapon_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/07/26 17:48:08 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "libft.h"
#include "entities_bonus.h"

static void	update_player_weapon_switching(
	t_player_weapon *weapon_info,
	t_weapon *weapon
)
{
	if (weapon_info->frame_update_delta < PLAYER_WEAPON_ANIMATION_UPDATE)
		return ;
	weapon_info->frame_update_delta = 0;
	if (weapon_info->weapon_state == WEAPON_STATE_HOLSTERING)
	{
		weapon_info->draw_offset.y += PLAYER_WEAPON_SWITCH_OFFSET;
		if (weapon_info->draw_offset.y >= weapon->curr_frame->height)
		{
			weapon_info->weapon_state = WEAPON_STATE_DRAWING;
			weapon_info->curr_weapon_index = weapon_info->next_weapon_index;
			weapon_info->curr_weapon = \
				weapon_info->weapons[weapon_info->curr_weapon_index];
		}
	}
	if (weapon_info->weapon_state == WEAPON_STATE_DRAWING)
	{
		weapon_info->draw_offset.y -= PLAYER_WEAPON_SWITCH_OFFSET;
		if (weapon_info->draw_offset.y <= 0)
			weapon_info->weapon_state = WEAPON_STATE_IDLE;
	}
}

static void	update_player_weapon_using(
	t_player_weapon *weapon_info,
	t_weapon *weapon,
	t_game *game
)
{
	if (weapon_info->frame_update_delta < PLAYER_ANIMATION_UPDATE)
		return ;
	weapon_info->frame_update_delta = 0;
	update_weapon(weapon, game);
	if (weapon->curr_frame == weapon->frame_default)
		weapon_info->weapon_state = WEAPON_STATE_IDLE;
}

void	update_player_weapon(
	t_player_weapon *weapon_info,
	t_weapon *weapon,
	t_game *game,
	float delta_time
)
{
	weapon_info->frame_update_delta += delta_time;
	if (weapon_info->weapon_state == WEAPON_STATE_USING)
		update_player_weapon_using(weapon_info, weapon, game);
	else if (
		weapon_info->weapon_state == WEAPON_STATE_HOLSTERING
		|| weapon_info->weapon_state == WEAPON_STATE_DRAWING
	)
		update_player_weapon_switching(weapon_info, weapon);
}
