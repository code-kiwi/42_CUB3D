/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boh_projectile_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:09:39 by root              #+#    #+#             */
/*   Updated: 2024/08/29 10:39:36 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

void	boh_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet)
{
	t_sprite_init(bullet->sprite, &anim[IDX_TXTR_BOH_PROJ_LIVE], WIN_HEIGHT);
	bullet->use = entity_projectile_use;
	bullet->speed = BULLET_SPEED;
	bullet->damage = BOH_RANGE_DAMAGE;
	bullet->animation = &anim[IDX_TXTR_BOH_PROJ_DEATH];
}
