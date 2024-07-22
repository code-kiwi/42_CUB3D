/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:04:12 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/22 14:11:06 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "weapons_bonus.h"
#include "libft.h"

bool	player_add_weapon(t_weapon *weapon, t_list **weapon_list)
{
	t_list	*weapon_link;

	if (weapon == NULL || weapon_list == NULL)
		return (false);
	weapon_link = ft_lstnew(weapon);
	if (weapon_link == NULL)
		return (false);
	ft_lstadd_back(weapon_list, weapon_link);
	return (true);
}

void	destroy_player_weapons(t_player *player)
{
	if (player == NULL || player->weapons == NULL)
		return ;
	ft_lstclear(&player->weapons, NULL);
}

bool	init_player_weapons(t_game *game, t_player *player)
{
	if (game == NULL)
		return (error_print(ERR_P_WEAPONS_CREATION), false);
	if (
		!player_add_weapon(&game->weapons[IDX_W1_HAND], &player->weapons)
		|| !player_add_weapon(&game->weapons[IDX_W1_HAND], &player->weapons)
	)
	{
		destroy_player_weapons(player);
		return (error_print(ERR_P_WEAPONS_CREATION), false);
	}
	player->curr_weapon = (t_weapon *) player->weapons->content;
	return (true);
}