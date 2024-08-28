/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mancubus_projectile_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:50:01 by brappo            #+#    #+#             */
/*   Updated: 2024/08/28 23:18:04 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

static void	mancubus_projectile_use(t_game *game, t_bullet *bullet)
{
	t_sprite	*sprite;
	t_vector	*player_pos;

	if (game == NULL || bullet == NULL)
		return ;
	sprite = bullet->sprite;
	sprite->next_animation = NULL;
	player_pos = &game->player.position;
	if (get_distance(player_pos, &bullet->sprite->position) < PLAYER_RADIUS)
		player_get_damage(game, bullet->damage);
	ft_lst_remove_if(&game->bullets, bullet, equal, free);
}

void	manc_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet)
{
	t_sprite_init(bullet->sprite, &anim[IDX_TXTR_MANC_FIREBALL],
		WIN_HEIGHT);
	bullet->use = mancubus_projectile_use;
	bullet->speed = BULLET_SPEED;
	bullet->damage = MANC_RANGE_DAMAGE;
}
