/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/27 16:12:40 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "ui_bonus.h"

int	mouse_release_handler(int button, int x, int y, t_game *game)
{
	if (button == MOUSE_LEFT && game->pause)
		mouse_release_pause_handler(x, y, game);
	if (button == MOUSE_LEFT && !game->pause)
		player_weapon_use_stop(&game->player.weapon_info, game);
	return (1);
}
