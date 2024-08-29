/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mancubus_projectile_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:50:01 by brappo            #+#    #+#             */
/*   Updated: 2024/08/29 10:39:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

void	manc_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet)
{
	t_sprite_init(bullet->sprite, &anim[IDX_TXTR_MANC_FIREBALL],
		WIN_HEIGHT);
	bullet->use = entity_projectile_use;
	bullet->speed = BULLET_SPEED;
	bullet->damage = MANC_RANGE_DAMAGE;
	bullet->animation = NULL;
}
