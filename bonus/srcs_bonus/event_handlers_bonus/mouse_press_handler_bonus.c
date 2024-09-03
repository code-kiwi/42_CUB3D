/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/09/03 14:12:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_press_handler(int button, int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (game == NULL)
		error_exit(NULL, ERR_ARG);
	if (game->state != STATE_PLAYING)
		return (0);
	if (button == MOUSE_LEFT)
		player_weapon_use(&game->player.weapon_info, game);
	else if (button == MOUSE_WHEEL_DOWN)
		player_select_next_weapon(&game->player.weapon_info);
	else if (button == MOUSE_WHEEL_UP)
		player_select_prev_weapon(&game->player.weapon_info);
	return (1);
}
