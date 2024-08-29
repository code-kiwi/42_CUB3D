/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:12:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/29 13:46:32 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

static void	init_w1_hand(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W1_HAND].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W1_PUNCH].textures;
	weapon->frames_bullet_live = NULL;
	weapon->frames_bullet_death = NULL;
	weapon->target = NULL;
	weapon->animation_update = game->anim[IDX_TXTR_W1_HAND].wait;
	weapon->load_capacity = W1_HAND_LOAD_CAPACITY;
	weapon->remaining_use = W1_HAND_INITIAL_USES;
	weapon->damage = W1_HAND_DAMAGES;
	weapon->range = W1_HAND_RANGE;
	weapon->is_limited = false;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_hand;
	weapon->using = false;
}

static void	init_w2_pistol(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W2_PISTOL].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W2_PISTOL].textures->next;
	weapon->frames_bullet_live = game->anim[IDX_TXTR_W_BUL_BASIC_LIVE].textures;
	weapon->frames_bullet_death = game->anim[IDX_TXTR_W_BUL_BASIC_DEATH].textures;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W2_PISTOL].wait;
	weapon->load_capacity = W2_PISTOL_LOAD_CAPACITY;
	weapon->remaining_use = W2_PISTOL_INITIAL_USES;
	weapon->damage = W2_PISTOL_DAMAGES;
	weapon->range = W2_PISTOL_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_no_bullet;
	weapon->using = false;
}

static void	init_w3_chaingun(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W3_CHAINGUN].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W3_CHAINGUN].textures->next;
	weapon->frames_bullet_live = NULL;
	weapon->frames_bullet_death = NULL;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W3_CHAINGUN].wait;
	weapon->load_capacity = W3_CHAINGUN_LOAD_CAPACITY;
	weapon->remaining_use = W3_CHAINGUN_INITIAL_USES;
	weapon->damage = W3_CHAINGUN_DAMAGES;
	weapon->range = W3_CHAINGUN_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = true;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
}

bool	init_weapons(t_game *game)
{
	if (game == NULL)
		return (error_print(ERR_WEAPONS_CREATION), false);
	init_w1_hand(&game->weapons[IDX_W1_HAND], game);
	init_w2_pistol(&game->weapons[IDX_W2_PISTOL], game);
	init_w3_chaingun(&game->weapons[IDX_W3_CHAINGUN], game);
	if (!init_resize_imgs(game->weapons, &game->mlx))
		return (error_print(ERR_WEAPONS_RESIZE), false);
	init_all_weapon_positions(game->weapons, &game->mlx);
	return (true);
}
