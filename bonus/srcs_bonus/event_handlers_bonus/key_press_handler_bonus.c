/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:16:10 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 09:34:34 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "door_bonus.h"

/**
 * @brief Handles the keyboard press key events
 * @param game The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_press_handler(int key, t_game *game)
{
	t_player_weapon	*weapon_info;

	weapon_info = &game->player.weapon_info;
	if (game == NULL)
		error_exit(NULL, ERR_ARG);
	else if (game->game_over || game->game_won)
		return (0);
	else if (key == KEY_W)
		game->player.walk_direction[FRONT] = true;
	else if (key == KEY_S)
		game->player.walk_direction[BACK] = true;
	else if (key == KEY_A)
		game->player.walk_direction[LEFT] = true;
	else if (key == KEY_D)
		game->player.walk_direction[RIGHT] = true;
	else if (key == KEY_E)
		open_looked_door(game->player.look_ray, &game->map);
	else if (key >= FIRST_WEAPON_KEY && key <= LAST_WEAPON_KEY
		&& !game->pause)
	{
		player_select_weapon(weapon_info, key - FIRST_WEAPON_KEY);
	}
	return (0);
}
