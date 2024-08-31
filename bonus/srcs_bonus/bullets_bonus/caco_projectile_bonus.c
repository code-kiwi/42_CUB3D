/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caco_projectile_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:09:39 by root              #+#    #+#             */
/*   Updated: 2024/08/31 19:56:02 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

void	caco_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet)
{
	if (anim == NULL || bullet == NULL)
		return ;
	t_sprite_init(bullet->sprite, &anim[IDX_TXTR_CACO_PROJ_LIVE], WIN_HEIGHT);
	bullet->use = entity_projectile_use;
	bullet->speed = BULLET_SPEED;
	bullet->damage = CACO_RANGE_DAMAGE;
	bullet->animation = &anim[IDX_TXTR_CACO_PROJ_DEATH];
}
