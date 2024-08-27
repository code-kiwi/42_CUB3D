/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/08/27 14:00:10 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"

int	mouse_release_handler(int button, int x, int y, t_game *game)
{
	if (button == MOUSE_LEFT && game->pause)
		mouse_release_pause_handler(x, y, game);
	else if (button == MOUSE_LEFT && game->game_over)
		mouse_release_gameover_handler(x, y, game);
	else if (button == MOUSE_LEFT)
		player_weapon_use_stop(&game->player.weapon_info, game);
	return (1);
}
