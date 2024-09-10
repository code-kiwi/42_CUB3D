/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_level_selection1_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/05 16:10:31 by mhotting         ###   ########.fr       */
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

void	reload_level(t_game *game)
{
	ssize_t	map_index;

	if (game == NULL || game->curr_map_index == NO_MAP_LOADED_INDEX)
		return ;
	map_index = game->curr_map_index;
	game_unload_map(game);
	game_load_map(game, map_index);
}
