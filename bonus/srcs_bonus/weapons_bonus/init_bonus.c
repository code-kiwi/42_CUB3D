/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:12:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/31 00:46:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"
#include "bullets_bonus.h"

static void	init_w1_hand(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W1_HAND].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W1_PUNCH].textures;
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
	weapon->bullet_speed = 0;
	weapon->bullet_init = NULL;
	weapon->bullet_live_anim = NULL;
	weapon->bullet_death_anim = NULL;
	weapon->bullet_use = NULL;
	weapon->bullet_cooldown_effect = W1_HAND_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W1_HAND_COOLDOWN_EFFECT;
}

static void	init_w2_pistol(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W2_PISTOL].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W2_PISTOL].textures->next;
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
	weapon->bullet_speed = W2_PISTOL_BULLET_SPEED;
	weapon->bullet_init = NULL;
	weapon->bullet_live_anim = NULL;
	weapon->bullet_death_anim = NULL;
	weapon->bullet_use = NULL;
	weapon->bullet_cooldown_effect = W2_PISTOL_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W2_PISTOL_COOLDOWN_EFFECT;
}

static void	init_w3_chaingun(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W3_CHAINGUN].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W3_CHAINGUN].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W3_CHAINGUN].wait;
	weapon->load_capacity = W3_CHAINGUN_LOAD_CAPACITY;
	weapon->remaining_use = W3_CHAINGUN_INITIAL_USES;
	weapon->damage = W3_CHAINGUN_DAMAGES;
	weapon->range = W3_CHAINGUN_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = true;
	weapon->action = use_weapon_no_bullet;
	weapon->using = false;
	weapon->bullet_speed = W3_CHAINGUN_BULLET_SPEED;
	weapon->bullet_init = NULL;
	weapon->bullet_live_anim = NULL;
	weapon->bullet_death_anim = NULL;
	weapon->bullet_use = NULL;
	weapon->bullet_cooldown_effect = W3_CHAINGUN_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W3_CHAINGUN_COOLDOWN_EFFECT;
}

static void	init_w4_bf_gun(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W4_BF_GUN].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W4_BF_GUN].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W4_BF_GUN].wait;
	weapon->load_capacity = W4_BF_GUN_LOAD_CAPACITY;
	weapon->remaining_use = W4_BF_GUN_INITIAL_USES;
	weapon->damage = W4_BF_GUN_DAMAGES;
	weapon->range = W4_BF_GUN_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = true;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
	weapon->bullet_speed = W4_BF_GUN_BULLET_SPEED;
	weapon->bullet_init = player_gun_proj_init;
	weapon->bullet_live_anim = &game->anim[IDX_TXTR_W_BUL_BASIC_LIVE];
	weapon->bullet_death_anim = &game->anim[IDX_TXTR_W_BUL_BASIC_DEATH];
	weapon->bullet_use = player_basic_projectile_use;
	weapon->bullet_cooldown_effect = W4_BF_GUN_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W4_BF_GUN_COOLDOWN_EFFECT;
}

static void	init_w5_plasma(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W5_PLASMA].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W5_PLASMA].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W5_PLASMA].wait;
	weapon->load_capacity = W5_PLASMA_LOAD_CAPACITY;
	weapon->remaining_use = W5_PLASMA_INITIAL_USES;
	weapon->damage = W5_PLASMA_DAMAGES;
	weapon->range = W5_PLASMA_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
	weapon->bullet_speed = W5_PLASMA_BULLET_SPEED;
	weapon->bullet_init = player_gun_proj_init;
	weapon->bullet_live_anim = &game->anim[IDX_TXTR_W_BUL_PLASMA_LIVE];
	weapon->bullet_death_anim = &game->anim[IDX_TXTR_W_BUL_PLASMA_DEATH];
	weapon->bullet_use = player_basic_projectile_use;
	weapon->bullet_cooldown_effect = W5_PLASMA_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W5_PLASMA_COOLDOWN_EFFECT;
}

static void	init_w6_shotgun(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W6_SHOTGUN].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W6_SHOTGUN].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W6_SHOTGUN].wait;
	weapon->load_capacity = W6_SHOTGUN_LOAD_CAPACITY;
	weapon->remaining_use = W6_SHOTGUN_INITIAL_USES;
	weapon->damage = W6_SHOTGUN_DAMAGES;
	weapon->range = W6_SHOTGUN_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
	weapon->bullet_speed = W6_SHOTGUN_BULLET_SPEED;
	weapon->bullet_init = player_gun_proj_init;
	weapon->bullet_live_anim = &game->anim[IDX_TXTR_W_BUL_BASIC_LIVE];
	weapon->bullet_death_anim = &game->anim[IDX_TXTR_W_BUL_BASIC_DEATH];
	weapon->bullet_use = player_basic_projectile_use;
	weapon->bullet_cooldown_effect = W6_SHOTGUN_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W6_SHOTGUN_COOLDOWN_EFFECT;
}

static void	init_w7_rocket(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W7_ROCKET].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W7_ROCKET].textures->next;
	weapon->target = (t_image *) game->anim[IDX_TXTR_TARGET1].textures->content;
	weapon->animation_update = game->anim[IDX_TXTR_W7_ROCKET].wait;
	weapon->load_capacity = W7_ROCKET_LOAD_CAPACITY;
	weapon->remaining_use = W7_ROCKET_INITIAL_USES;
	weapon->damage = W7_ROCKET_DAMAGES;
	weapon->range = W7_ROCKET_RANGE;
	weapon->is_limited = true;
	weapon->is_use_continuous = false;
	weapon->action = use_weapon_bullet;
	weapon->using = false;
	weapon->bullet_speed = W7_ROCKET_BULLET_SPEED;
	weapon->bullet_init = player_gun_proj_init;
	weapon->bullet_live_anim = &game->anim[IDX_TXTR_W_BUL_ROCKET_LIVE];
	weapon->bullet_death_anim = &game->anim[IDX_TXTR_W_BUL_ROCKET_DEATH];
	weapon->bullet_use = player_basic_projectile_use;
	weapon->bullet_cooldown_effect = W7_ROCKET_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W7_ROCKET_COOLDOWN_EFFECT;
}

static void	init_w8_chainsaw(t_weapon *weapon, t_game *game)
{
	weapon->frame_default = \
		(t_image *) game->anim[IDX_TXTR_W8_CHAINSAW].textures->content;
	weapon->curr_frame = weapon->frame_default;
	weapon->curr_frame_link = NULL;
	weapon->frames_action = game->anim[IDX_TXTR_W8_CHAINSAW].textures->next;
	weapon->target = NULL;
	weapon->animation_update = game->anim[IDX_TXTR_W8_CHAINSAW].wait;
	weapon->load_capacity = W8_CHAINSAW_LOAD_CAPACITY;
	weapon->remaining_use = W8_CHAINSAW_INITIAL_USES;
	weapon->damage = W8_CHAINSAW_DAMAGES;
	weapon->range = W8_CHAINSAW_RANGE;
	weapon->is_limited = false;
	weapon->is_use_continuous = true;
	weapon->action = use_weapon_hand;
	weapon->using = false;
	weapon->bullet_speed = W8_CHAINSAW_BULLET_SPEED;
	weapon->bullet_init = NULL;
	weapon->bullet_live_anim = NULL;
	weapon->bullet_death_anim = NULL;
	weapon->bullet_use = NULL;
	weapon->bullet_cooldown_effect = W8_CHAINSAW_BULLET_COOLDOWN_EFFECT;
	weapon->cooldown_curr = 0;
	weapon->cooldown_effect = W8_CHAINSAW_COOLDOWN_EFFECT;
}

bool	init_weapons(t_game *game)
{
	if (game == NULL)
		return (error_print(ERR_WEAPONS_CREATION), false);
	init_w1_hand(&game->weapons[IDX_W1_HAND], game);
	init_w2_pistol(&game->weapons[IDX_W2_PISTOL], game);
	init_w3_chaingun(&game->weapons[IDX_W3_CHAINGUN], game);
	init_w4_bf_gun(&game->weapons[IDX_W4_BF_GUN], game);
	init_w5_plasma(&game->weapons[IDX_W5_PLASMA], game);
	init_w6_shotgun(&game->weapons[IDX_W6_SHOTGUN], game);
	init_w7_rocket(&game->weapons[IDX_W7_ROCKET], game);
	init_w8_chainsaw(&game->weapons[IDX_W8_CHAINSAW], game);
	if (!init_resize_imgs(game->weapons, &game->mlx))
		return (error_print(ERR_WEAPONS_RESIZE), false);
	init_all_weapon_positions(game->weapons, &game->mlx);
	return (true);
}
