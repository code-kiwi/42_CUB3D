/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:02:42 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:00:05 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "player.h"
#include "event_handlers.h"
#include "libft.h"
#include "mlx.h"

#include <stdio.h>

bool	init_textures(t_game *game)
{
	size_t	index;
	char	*filename;

	index = 0;
	while (index < MAP_NB_TEXTURES)
	{
		filename = game->map.textures[index];
		if (filename == NULL
			|| filename[0] == '\0')
		{
			error_print(ERR_MISSING_TEXTURES);
			return (false);
		}
		filename[ft_strlen(filename) - 1] = '\0';
		if (!t_image_import_file(&game->textures[index], filename,
				game->mlx.mlx_ptr))
		{
			error_print(ERR_INIT_TEXTURES);
			return (false);
		}
		index++;
	}
	return (true);
}

/**
 * @brief Initializes the given t_game
 * @param game The structure to init
 * @return true on SUCCESS, false on ERROR
*/
bool	t_game_init(t_game *game)
{
	if (game == NULL)
		return (false);
	if (!t_player_init(&game->player, &game->map))
		return (error_print(ERR_PLAYER_INIT), false);
	if (!t_mlx_init(&game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE))
		return (error_print(ERR_MLX_INIT), false);
	if (!init_textures(game))
		return (false);
	if (!add_event_handlers(game))
		return (error_print(ERR_HOOKS), false);
	return (true);
}
