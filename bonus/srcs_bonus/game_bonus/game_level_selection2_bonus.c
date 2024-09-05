/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_level_selection2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/05 14:33:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	select_level1(t_game *game)
{
	if (game == NULL || !game_load_map(game, MAP0_IDX))
		error_exit(game, ERR_MAP_LOAD);
}

void	select_level2(t_game *game)
{
	if (game == NULL || !game_load_map(game, MAP1_IDX))
		error_exit(game, ERR_MAP_LOAD);
}

void	select_level3(t_game *game)
{
	if (game == NULL || !game_load_map(game, MAP2_IDX))
		error_exit(game, ERR_MAP_LOAD);
}

void	select_level4(t_game *game)
{
	if (game == NULL || !game_load_map(game, MAP3_IDX))
		error_exit(game, ERR_MAP_LOAD);
}

void	select_level5(t_game *game)
{
	if (game == NULL || !game_load_map(game, MAP4_IDX))
		error_exit(game, ERR_MAP_LOAD);
}
