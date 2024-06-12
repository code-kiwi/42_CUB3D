/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 15:06:20 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx_api.h"
#include "libft.h"

int	game_loop(t_mlx *mlx)
{
	if (mlx == NULL)
		return (-1);
	mlx->event_loop_counter++;
	if (mlx->event_loop_counter == EVENT_LOOP_FRAME_TARGET)
	{
		mlx->event_loop_counter = 0;
		ft_printf("LOOP\n");
	}
	return (0);
}
