/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revenant_projectile_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:09:39 by root              #+#    #+#             */
/*   Updated: 2024/08/28 23:16:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

static void	revenant_projectile_use(t_game *game, t_bullet *bullet)
{
	t_sprite	*sprite;
	t_vector	*player_pos;

	if (game == NULL || bullet == NULL)
		return ;
	sprite = bullet->sprite;
	set_animation(sprite, &game->anim[IDX_TXTR_REV_PROJ_DEATH]);
	sprite->next_animation = NULL;
	player_pos = &game->player.position;
	if (get_distance(player_pos, &bullet->sprite->position) < PLAYER_RADIUS)
		player_get_damage(game, bullet->damage);
	ft_lst_remove_if(&game->bullets, bullet, equal, free);
}

void	rev_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet)
{
	t_sprite_init(bullet->sprite, &anim[IDX_TXTR_REV_PROJ_LIVE], WIN_HEIGHT);
	bullet->use = revenant_projectile_use;
	bullet->speed = BULLET_SPEED;
	bullet->damage = REV_RANGE_DAMAGE;
}
