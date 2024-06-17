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
#include "mlx_api.h"

static bool	init_textures(t_game *game)
{
	size_t	index;
	char	*filename;

	index = 0;
	while (index < MAP_NB_TEXTURES)
	{
		filename = game->map.textures[index];
		if (filename == NULL || filename[0] == '\0' || filename[0] == '\n')
			return (error_print(ERR_MISSING_TEXTURES), false);
		filename[ft_strlen(filename) - 1] = '\0';
		if (!check_extension(filename, ".xpm"))
			return (error_print(ERR_TEXTURE_EXTENSION), false);
		if (!t_image_import_file(&game->textures[index], filename,
				game->mlx.mlx_ptr))
			return (error_print(ERR_INIT_TEXTURES), false);
		index++;
	}
	return (true);
}

static bool	init_color(unsigned int *color_result, char *color)
{
	char			**components;
	ssize_t			index;
	bool			error;
	size_t			length;

	components = ft_split(color, ",\n");
	if (components == NULL)
		return (NULL);
	length = array_length((void **)components);
	if (length != 3)
	{
		free_array(components, length, true);
		return (error_print(ERR_MISSING_COLOR), false);
	}
	index = -1;
	error = false;
	while (++index < 3 && !error)
		error = !is_number(components[index])
			|| (ft_strlen(components[index]) > 3) || error;
	error = set_color(color_result, atoi(components[0]), atoi(components[1]),
			atoi(components[2])) || error;
	free_array(components, 3, true);
	if (error)
		error_print(ERR_BAD_COLOR);
	return (!error);
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
		return (false);
	if (!init_color(&game->ground_color, game->map.textures[4])
		|| !init_color(&game->ceiling_color, game->map.textures[5]))
		return (false);
	if (!init_textures(game))
		return (false);
	if (!add_event_handlers(game))
		return (error_print(ERR_HOOKS), false);
	if (!t_mlx_init(&game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE))
		return (false);
	return (true);
}
