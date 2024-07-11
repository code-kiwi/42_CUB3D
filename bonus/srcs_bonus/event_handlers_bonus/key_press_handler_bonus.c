/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/11 11:27:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "libft.h"
#include "door_bonus.h"
#include "item_bonus.h"

void	interact(t_game *game)
{
	t_item	*item_in_hand;

	item_in_hand = game->player.item_in_hand;
	if (game->player.aimed_sprite == NULL)
		open_looked_door(game->player.look_ray, &game->map);
	else if (item_in_hand != NULL && item_in_hand->remaining_usage != 0)
	{
		item_in_hand->use_item(game);
		if (item_in_hand->remaining_usage != -1)
			item_in_hand->remaining_usage--;
	}
}

/**
 * @brief Handles the keyboard press key events
 * @param game The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_press_handler(int key, t_game *game)
{
	if (game == NULL)
		error_exit(NULL, ERR_ARG);
	else if (key == KEY_W)
		game->player.is_walking[FRONT] = true;
	else if (key == KEY_S)
		game->player.is_walking[BACK] = true;
	else if (key == KEY_A)
		game->player.is_walking[LEFT] = true;
	else if (key == KEY_D)
		game->player.is_walking[RIGHT] = true;
	else if (key == KEY_E)
		interact(game);
	return (0);
}
