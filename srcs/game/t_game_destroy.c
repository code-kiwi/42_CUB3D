/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:01:50 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:01:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx_api.h"

#include <stdio.h>
/**
 * @brief Destroys the given t_game
 * @param game The structure to destroy
*/
void	t_game_destroy(t_game *game)
{
	if (game == NULL)
		return ;
	t_mlx_destroy(&game->mlx);
	printf("DESTROY\n");
	free_array(game->map.tiles, game->map.lines_count, true);
	free_array(game->map.textures, MAP_NB_IDS, false);
	free(game->map.lines_lengths);
}
