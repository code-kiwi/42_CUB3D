/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:04:12 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/23 13:06:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "weapons_bonus.h"
#include "libft.h"

void	player_select_prev_weapon(t_player *player)
{
	if (
		player == NULL
		|| player->curr_weapon->curr_frame != player->curr_weapon->frame_default
	)
		return ;
	if (player->curr_weapon_index == 0)
	{
		while (player->weapons[player->curr_weapon_index + 1])
			player->curr_weapon_index++;
	}
	else
		player->curr_weapon_index--;
	player->curr_weapon = player->weapons[player->curr_weapon_index];
}

void	player_select_next_weapon(t_player *player)
{
	if (
		player == NULL
		|| player->curr_weapon->curr_frame != player->curr_weapon->frame_default
	)
		return ;
	player->curr_weapon_index++;
	if (player->weapons[player->curr_weapon_index] == NULL)
		player->curr_weapon_index = 0;
	player->curr_weapon = player->weapons[player->curr_weapon_index];
}

void	player_weapon_use(t_player *player, t_game *game)
{
	player->frame_update_delta = 0;
	use_weapon(player->curr_weapon, game);
}

bool	init_player_weapons(t_game *game, t_player *player)
{
	if (game == NULL)
		return (error_print(ERR_P_WEAPONS_CREATION), false);
	ft_bzero(&player->weapons, (NB_TOT_WEAPONS + 1) * sizeof(t_weapon *));
	player->weapons[0] = &game->weapons[0];
	player->weapons[1] = &game->weapons[1];
	player->curr_weapon_index = 0;
	player->curr_weapon = player->weapons[player->curr_weapon_index];
	return (true);
}
