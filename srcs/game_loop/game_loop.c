/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 14:02:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx_api.h"
#include "libft.h"

int	game_loop(t_cub_data *data)
{
	if (data == NULL)
		error_exit(data, ERR_MSG_GAME_LOOP);
	data->mlx.event_loop_counter++;
	if (data->mlx.event_loop_counter == EVENT_LOOP_FRAME_TARGET)
	{
		if (!t_mlx_render(&data->mlx))
			error_exit(data, ERR_MSG_RENDER);
	}
	return (0);
}
