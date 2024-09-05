/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_level_selection1_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/05 14:31:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	game_reach_level_selection(t_game *game)
{
	if (game == NULL)
		return ;
	game->state = STATE_LEVEL_SELECTION;
}

void	quit_level(t_game *game)
{
	if (game == NULL)
		return ;
	game_unload_map(game);
	game->state = STATE_LEVEL_SELECTION;
}
