/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_pause_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 07:19:29 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/26 07:32:33 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	game_pause_switch(t_game *game)
{
	if (game == NULL)
		return ;
	game->pause = !game->pause;
	if (game->pause)
		t_mlx_sync_images(&game->mlx);
}

void	game_pause_close(t_game *game)
{
	if (game == NULL)
		return ;
	game->pause = false;
}
