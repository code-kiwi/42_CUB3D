/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_level_selection2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:03 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/05 12:42:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"
#include "mlx.h"
#include "entities_bonus.h"

static bool	init_textures(t_game *game)
{
	size_t			index;
	t_mlx_coords	*texture_size;
	char			*filename;
	t_image			texture;

	index = 0;
	while (index < MAP_NB_IDS)
	{
		filename = game->map->textures[index];
		texture_size = &game->map->texture_size[index];
		if (filename == NULL || filename[0] == '\0')
			return (error_print_string(ERR_MISSING_TEXTURES, filename), false);
		if (!check_extension(filename, ".xpm"))
			return (error_print_string(ERR_TEXTURE_EXTENSION, filename), false);
		if (!t_image_import_file(&texture, filename, game->mlx.mlx_ptr, NULL))
			return (error_print_string(ERR_INIT_TEXTURES, filename), false);
		game->anim[index].textures = create_animation_textures(&texture, texture_size, game->mlx.mlx_ptr, filename);
		mlx_destroy_image(game->mlx.mlx_ptr, texture.ptr);
		if (game->anim[index].textures == NULL)
			return (false);
		index++;
	}
	return (true);
}

bool	game_load_map(t_game *game, size_t map_index)
{
	bool	load_ok;

	if (game == NULL || map_index > NB_MAPS)
		return (false);
	game->map = &game->maps[map_index];
	game->anim = game->anims[map_index];
	load_ok = \
		init_textures(game)
		&& t_player_init(&game->player, game->map, game)
		&& init_sprites(game)
		&& init_doors(game)
		&& init_entities(game)
		&& init_map_draw(&game->map->draw, game->map, game)
		&& init_radar(&game->radar, &game->mlx)
		&& init_weapons(game)
		&& init_player_weapons(game, &game->player.weapon_info)
		&& init_hud(game, &game->hud);
	if (!load_ok)
		return (false); // unload map components!!!
	game->state = STATE_PLAYING;
	return (true);
}

void	game_unload_map(t_game *game)
{
	size_t	i;

	if (game == NULL)
		return ;
	destroy_radar(&game->radar, game->mlx.mlx_ptr);
	if (game->doors != NULL)
	{
		free(game->doors);
		game->doors = NULL;
	}
	ft_lstclear(&game->sprites, free);
	ft_lstclear(&game->bullets, free);
	ft_lstclear(&game->entities, t_entity_destroy);
	i = 0;
	while (i < game->map->lines_count)
	{
		ft_strlcpy(game->map->tiles[i], game->map->tiles_save[i], ft_strlen(game->map->tiles[i]) + 1);
		i++;
	}
	game->map = NULL;
	game->anim = NULL;
}

void	quit_level(t_game *game)
{
	game_unload_map(game);
	game->state = STATE_LEVEL_SELECTION;
}

void	select_level1(t_game *game)
{
	if (!game_load_map(game, MAP0_IDX))
		error_exit(game, ERR_MAP_LOAD);
}

void	select_level2(t_game *game)
{
	if (!game_load_map(game, MAP1_IDX))
		error_exit(game, ERR_MAP_LOAD);
}

void	select_level3(t_game *game)
{
	if (!game_load_map(game, MAP2_IDX))
		error_exit(game, ERR_MAP_LOAD);
}

void	select_level4(t_game *game)
{
	if (!game_load_map(game, MAP3_IDX))
		error_exit(game, ERR_MAP_LOAD);
}

void	select_level5(t_game *game)
{
	if (!game_load_map(game, MAP4_IDX))
		error_exit(game, ERR_MAP_LOAD);
}