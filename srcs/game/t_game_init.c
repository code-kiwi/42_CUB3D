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

bool	set_color(unsigned int *result, int r, int g, int b)
{
	t_argb_color	color;

	if (r < 0 || g < 0 || b < 0
		|| r > 255 || g > 255 || b > 255)
		return (false);
	color.rgba.a = 255;
	color.rgba.r = r;
	color.rgba.g = g;
	color.rgba.b = b;
	*result = color.val;
	return (true);
}

bool	init_color(unsigned int *color_result, char *color)
{
	char			**components;
	size_t			index;
	size_t			length;
	bool			error;

	if (!color || color[0] == '\n' || !*color)
		return (false);
	components = ft_split(color, ",\n");
	length = array_length((void **)components);
	if (components == NULL || length != 3)
		return (free_array(components, length, true), false);
	index = 0;
	error = false;
	while (index < 3)
	{
		error = !is_number(components[index]) | error;
		index++;
	}
	error = set_color(color_result, atoi(components[0]), atoi(components[1]),
			atoi(components[2])) | error;
	free_array(components, 3, true);
	return (error);
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
	if (!init_color(&game->ground_color, game->map.textures[4]))
		return (false);
	if (!init_color(&game->ceiling_color, game->map.textures[5]))
		return (false);
	return (true);
}
