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
#include "mlx_api_bonus.h"
#include "door_bonus.h"
#include "map_bonus.h"
#include "sprite_bonus.h"
#include "ui_bonus.h"
#include "animation_bonus.h"
#include "mlx.h"
#include "entities_bonus.h"
#include "radar_bonus.h"

static bool	init_textures(t_game *game)
{
	size_t			index;
	t_mlx_coords	*texture_size;
	char			*filename;
	t_image			texture;

	index = 0;
	while (index < MAP_NB_IDS)
	{
		filename = game->map.textures[index];
		texture_size = &game->map.texture_size[index];
		if (filename == NULL || filename[0] == '\0')
			return (error_print(ERR_MISSING_TEXTURES), false);
		if (!check_extension(filename, ".xpm"))
			return (error_print(ERR_TEXTURE_EXTENSION), false);
		if (!t_image_import_file(&texture, filename, game->mlx.mlx_ptr, NULL))
			return (error_print(ERR_INIT_TEXTURES), false);
		game->textures[index] = create_animation(&texture, texture_size, \
			game->mlx.mlx_ptr);
		mlx_destroy_image(game->mlx.mlx_ptr, texture.ptr);
		if (game->textures[index] == NULL)
			return (false);
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
	game->bullets = NULL;
	return (
		t_mlx_init(&game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE)
		&& t_player_init(&game->player, &game->map, game)
		&& init_textures(game)
		&& init_sprites(game)
		&& init_all_ui(game)
		&& init_doors(game)
		&& init_entities(game)
		&& init_map_draw(&game->map.draw, &game->map, game)
		&& init_radar(&game->radar, &game->mlx)
		&& init_weapons(game)
		&& init_player_weapons(game, &game->player)
		&& t_mlx_launch(&game->mlx)
		&& add_event_handlers(game)
	);
}
