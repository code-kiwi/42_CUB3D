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

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "mlx.h"
#include "sprite_bonus.h"
#include "animation_bonus.h"

/**
 * @brief Destroys the given t_game
 * @param game The structure to destroy
*/
void	t_game_destroy(t_game *game)
{
	size_t	index;

	if (game == NULL)
		return ;
	index = 0;
	while (index < MAP_NB_IDS)
	{
		destroy_animation(game->textures[index], game->mlx.mlx_ptr, true);
		index++;
	}
	t_mlx_destroy(&game->mlx);
	free_map(&game->map);
	if (game->doors != NULL)
		free(game->doors);
	ft_lstclear(&game->sprites, free);
}
