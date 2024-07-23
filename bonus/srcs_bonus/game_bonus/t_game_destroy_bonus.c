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
#include "entities_bonus.h"

/**
 * @brief Destroys the given t_game
 * @param game The structure to destroy
*/
void	t_game_destroy(t_game *game)
{
	size_t	index;
	t_list	*animation_textures;

	if (game == NULL)
		return ;
	index = 0;
	destroy_all_ui(game);
	destroy_player(&game->player, game->mlx.mlx_ptr);
	while (index < MAP_NB_IDS)
	{
		animation_textures = game->animations[index].textures;
		destroy_animation_textures(animation_textures, game->mlx.mlx_ptr);
		index++;
	}
	destroy_radar(&game->radar, game->mlx.mlx_ptr);
	t_mlx_destroy(&game->mlx);
	free_map(&game->map);
	if (game->doors != NULL)
		free(game->doors);
	ft_lstclear(&game->sprites, free);
	ft_lstclear(&game->bullets, free);
	ft_lstclear(&game->entities, t_entity_destroy);
}

void	t_game_destroy_and_exit(t_game *game)
{
	if (game != NULL)
		t_game_destroy(game);
	exit(EXIT_SUCCESS);
}
