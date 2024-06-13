/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:25:06 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:03:19 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "event_handlers.h"
#include "mlx_api.h"
#include "libft.h"

/**
 * @brief Adds all the event handlers to the given t_cub_data structure
 * 
 * Adds loop, destroy and keyboard handlers
 * @param data The t_cub_data instance which needs the handlers
 * @return true on SUCCESS, false on ERROR
*/
bool	add_event_handlers(t_cub_data *data)
{
	if (data == NULL)
		return (false);
	if (
		!t_mlx_add_hook(&data->mlx, destroy_handler, data, HOOK_DESTROY)
		|| !t_mlx_add_hook(&data->mlx, keyboard_handler, data, HOOK_KEY)
		|| !t_mlx_add_hook(&data->mlx, game_loop, data, HOOK_LOOP)
	)
		return (false);
	return (true);
}
