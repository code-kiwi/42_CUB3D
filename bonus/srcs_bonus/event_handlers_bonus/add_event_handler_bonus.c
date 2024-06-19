/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:25:06 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/19 11:07:11 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "mlx_api_bonus.h"
#include "libft.h"

/**
 * @brief Adds all the event handlers to the given t_game structure
 * 
 * Adds loop, destroy and keyboard handlers
 * @param data The t_game instance which needs the handlers
 * @return true on SUCCESS, false on ERROR
*/
bool	add_event_handlers(t_game *data)
{
	if (data == NULL)
		return (false);
	if (
		!t_mlx_add_hook(&data->mlx, destroy_handler, data, HOOK_DESTROY)
		|| !t_mlx_add_hook(&data->mlx, key_release_handler, data, \
			HOOK_KEY_RELEASE)
		|| !t_mlx_add_hook(&data->mlx, key_press_handler, data, HOOK_KEY_PRESS)
		|| !t_mlx_add_hook(&data->mlx, game_loop, data, HOOK_LOOP)
	)
		return (false);
	return (true);
}
