/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pause_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:19:29 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/17 19:52:12 by codekiwi         ###   ########.fr       */
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
	{
		game->map_opened = false;
		t_mlx_mouse_show(&game->mlx, &game->mouse_hidden);
		t_mlx_sync_images(&game->mlx);
	}
	else
		game_pause_close(game);
}

void	game_pause_close(t_game *game)
{
	if (game == NULL)
		return ;
	game->pause = false;
	disable_buttons_ui(&game->ui_pause);
	t_mlx_mouse_hide(&game->mlx, &game->mouse_hidden);
}
