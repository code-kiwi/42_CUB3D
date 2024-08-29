/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:04:12 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/29 23:40:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

void	player_select_prev_weapon(t_player_weapon *weapon_info)
{
	if (
		weapon_info == NULL
		|| weapon_info->weapon_state != WEAPON_STATE_IDLE
	)
		return ;
	weapon_info->weapon_state = WEAPON_STATE_HOLSTERING;
	weapon_info->frame_update_delta = 0;
	weapon_info->next_weapon_index = weapon_info->curr_weapon_index;
	if (weapon_info->next_weapon_index == 0)
	{
		while (weapon_info->weapons[weapon_info->next_weapon_index + 1])
			weapon_info->next_weapon_index++;
	}
	else
		weapon_info->next_weapon_index--;
}

void	player_select_next_weapon(t_player_weapon *weapon_info)
{
	if (
		weapon_info == NULL
		|| weapon_info->weapon_state != WEAPON_STATE_IDLE
	)
		return ;
	weapon_info->weapon_state = WEAPON_STATE_HOLSTERING;
	weapon_info->frame_update_delta = 0;
	weapon_info->next_weapon_index = weapon_info->curr_weapon_index;
	weapon_info->next_weapon_index++;
	if (weapon_info->weapons[weapon_info->next_weapon_index] == NULL)
		weapon_info->next_weapon_index = 0;
}

void	player_weapon_use(t_player_weapon *weapon_info, t_game *game)
{
	if (
		weapon_info == NULL || game == NULL
		|| (
			weapon_info->weapon_state != WEAPON_STATE_IDLE
			&& weapon_info->weapon_state != WEAPON_STATE_USING
		)
	)
		return ;
	weapon_info->frame_update_delta = 0;
	weapon_info->weapon_state = WEAPON_STATE_USING;
	use_weapon(weapon_info->curr_weapon, game);
}

void	player_weapon_use_stop(t_player_weapon *weapon_info, t_game *game)
{
	if (
		weapon_info == NULL || game == NULL
		|| !weapon_info->curr_weapon->is_use_continuous
		|| !weapon_info->curr_weapon->using
	)
		return ;
	stop_weapon(weapon_info->curr_weapon);
}

bool	init_player_weapons(t_game *game, t_player_weapon *weapon_info)
{
	if (game == NULL || weapon_info == NULL)
		return (error_print(ERR_P_WEAPONS_CREATION), false);
	ft_bzero(&weapon_info->weapons, (NB_TOT_WEAPONS + 1) * sizeof(t_weapon *));
	weapon_info->weapons[IDX_W1_HAND] = &game->weapons[IDX_W1_HAND];
	weapon_info->weapons[IDX_W2_PISTOL] = &game->weapons[IDX_W2_PISTOL];
	weapon_info->weapons[IDX_W3_CHAINGUN] = &game->weapons[IDX_W3_CHAINGUN];
	weapon_info->weapons[IDX_W4_BF_GUN] = &game->weapons[IDX_W4_BF_GUN];
	weapon_info->curr_weapon_index = 0;
	weapon_info->next_weapon_index = 0;
	weapon_info->curr_weapon = \
		weapon_info->weapons[weapon_info->curr_weapon_index];
	weapon_info->weapon_state = WEAPON_STATE_IDLE;
	weapon_info->draw_offset.x = 0;
	weapon_info->draw_offset.y = 0;
	weapon_info->frame_update_delta = 0;
	weapon_info->frame_update_delta_h_move = 0;
	weapon_info->draw_offset_sign = 1;
	return (true);
}
