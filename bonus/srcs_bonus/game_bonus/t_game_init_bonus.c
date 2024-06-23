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

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "event_handlers_bonus.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_api_bonus.h"
#include "door_bonus.h"

static bool	init_textures(t_game *game)
{
	size_t	index;
	char	*filename;

	index = 0;
	while (index < MAP_NB_IDS)
	{
		filename = game->map.textures[index];
		if (filename == NULL || filename[0] == '\0')
			return (error_print(ERR_MISSING_TEXTURES), false);
		if (!check_extension(filename, ".xpm"))
			return (error_print(ERR_TEXTURE_EXTENSION), false);
		if (!t_image_import_file(&game->textures[index], filename,
				game->mlx.mlx_ptr))
			return (error_print(ERR_INIT_TEXTURES), false);
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
	game->frame_time_usec = 1000000 / FPS;
	game->tick_last_frame = 0;
	if (!t_player_init(&game->player, &game->map, game))
		return (false);
	if (!t_mlx_init(&game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE))
		return (false);
	if (!init_textures(game))
		return (false);
	if (!t_mlx_launch(&game->mlx))
		return (false);
	if (!add_event_handlers(game))
		return (error_print(ERR_HOOKS), false);
	game->door_count = count_doors(&game->map);
	if (game->door_count != 0)
	{
		game->doors = ft_calloc(game->door_count, sizeof(t_door));
		if (game->doors == NULL)
			return (false);
		find_doors(&game->map, game->door_count, game->doors);
	}
	else
		game->doors = NULL;
	return (true);
}
