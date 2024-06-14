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
#include "event_handlers.h"
#include "libft.h"

void	init_params(t_param *param)
{
	param->fov = PI / 2;
	param->height = 920;
	param->width = 3;
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
	init_params(&game->param);
	game->player_rotation_rad = 7 * PI / 4;
	t_vector_init(&game->player_position, 1, 1);
	if (!t_mlx_init(&game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE))
		return (error_print(ERR_MSG_MLX_INIT), false);
	if (!add_event_handlers(game))
		return (error_print(ERR_MSG_HOOKS), false);
	return (true);
}
