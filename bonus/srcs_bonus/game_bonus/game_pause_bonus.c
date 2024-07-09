/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pause_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:19:29 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/09 09:39:21 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "ui_bonus.h"

void	game_pause_switch(t_game *game)
{
	if (game == NULL)
		return ;
	game->pause = !game->pause;
	if (game->pause)
		t_mlx_sync_images(&game->mlx);
	else
		disable_buttons_ui(&game->ui_pause);
}

void	game_pause_close(t_game *game)
{
	if (game == NULL)
		return ;
	game->pause = false;
	disable_buttons_ui(&game->ui_pause);
}
