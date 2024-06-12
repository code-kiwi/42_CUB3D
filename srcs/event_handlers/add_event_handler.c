/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:25:06 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 17:50:46 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "event_handlers.h"
#include "mlx_api.h"
#include "libft.h"

bool	add_event_handlers(t_cub_data *data)
{
	if (data == NULL)
		return (false);
	if (
		!t_mlx_add_hook(&data->mlx, (int (*)(void *))destroy_handler, data, \
			HOOK_DESTROY)
		|| !t_mlx_add_hook(&data->mlx, (int (*)(void *))keyboard_handler, \
			data, HOOK_KEY)
		|| !t_mlx_add_hook(&data->mlx, (int (*)(void *))game_loop, data, \
			HOOK_LOOP)
	)
		return (false);
	return (true);
}
