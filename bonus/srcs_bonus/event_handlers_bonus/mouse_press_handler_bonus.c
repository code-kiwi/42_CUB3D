/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/10 10:54:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

int	mouse_press_handler(int button, int x, int y, t_game *game)
{
	(void) x;
	(void) y;
	if (game == NULL)
		error_exit(NULL, ERR_ARG);
	if (button == MOUSE_LEFT)
		player_shoot(game);
	return (1);
}
