/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/03 09:26:58y brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_press_handler(int button, int x, int y, t_game *game)
{
	t_player_weapon	*weapon_info;

	(void) x;
	(void) y;
	weapon_info = &game->player.weapon_info;
	if (game == NULL)
		error_exit(NULL, ERR_ARG);
	if (game->game_over || game->game_won)
		return (0);
	if (button == MOUSE_LEFT && !game->pause)
		player_weapon_use(&game->player.weapon_info, game);
	else if (button == MOUSE_WHEEL_DOWN && !game->pause)
		player_select_weapon(weapon_info, weapon_info->curr_weapon_index + 1);
	else if (button == MOUSE_WHEEL_UP && !game->pause)
		player_select_weapon(weapon_info, weapon_info->curr_weapon_index - 1);
	return (1);
}
