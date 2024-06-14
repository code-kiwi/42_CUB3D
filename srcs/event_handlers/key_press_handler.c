/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 16:28:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "event_handlers.h"
#include "libft.h"

/**
 * @brief Handles the keyboard press key events
 * @param data The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_press_handler(int key, t_game *data)
{
	if (data == NULL)
		error_exit(NULL, ERR_ARG);
	if (key == KEY_RIGHT)
		data->player.turn_direction = 1;
	else if (key == KEY_LEFT)
		data->player.turn_direction = -1;
	else if (key == KEY_W)
		data->player.walk_dir = WALK_UP;
	else if (key == KEY_S)
		data->player.walk_dir = WALK_DOWN;
	else if (key == KEY_A)
		data->player.walk_dir = WALK_LEFT;
	else if (key == KEY_D)
		data->player.walk_dir = WALK_RIGHT;
	ft_printf("Key press: %d\n", key);
	return (0);
}
