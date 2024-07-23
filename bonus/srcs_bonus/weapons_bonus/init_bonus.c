/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:12:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/23 12:51:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_bonus.h"
#include "weapons_bonus.h"
#include "libft.h"

static void	init_w1_hand(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->textures[IDX_TXTR_W1_HAND]->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->textures[IDX_TXTR_W1_PUNCH];
	weapon->frames_bullet = NULL;
	weapon->target = NULL;
	weapon->num_loads = 0;
	weapon->load_capacity = 0;
	weapon->remaining_use = 0;
	weapon->is_limited = false;
	weapon->is_use_continuous = false;
	weapon->id = 'M';
}

static void	init_w2_pistol(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->textures[IDX_TXTR_W2_PISTOL]->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->textures[IDX_TXTR_W2_PISTOL]->next;
	weapon->frames_bullet = NULL;
	weapon->target = (t_image *) game->textures[IDX_TXTR_TARGET1]->content;
	weapon->num_loads = 2;
	weapon->load_capacity = 5;
	weapon->remaining_use = 5;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->id = 'N';
}

bool	init_weapons(t_game *game)
{
	if (game == NULL)
		return (error_print(ERR_WEAPONS_CREATION), false);
	init_w1_hand(&game->weapons[IDX_W1_HAND], game);
	init_w2_pistol(&game->weapons[IDX_W2_PISTOL], game);
	if (!init_resize_imgs(game->weapons, &game->mlx))
		return (error_print(ERR_WEAPONS_RESIZE), false);
	init_all_weapon_positions(game->weapons, &game->mlx);
	return (true);
}
