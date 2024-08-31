/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rocket_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:09:39 by root              #+#    #+#             */
/*   Updated: 2024/08/31 19:56:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

void	rocket_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet)
{
	if (anim == NULL || bullet == NULL)
		return ;
	t_sprite_init(bullet->sprite, &anim[IDX_TXTR_ROCKET_LIVE], WIN_HEIGHT);
	bullet->use = entity_projectile_use;
	bullet->speed = BULLET_SPEED;
	bullet->damage = ROCKET_DAMAGE;
	bullet->animation = &anim[IDX_TXTR_ROCKET_DEATH];
}
