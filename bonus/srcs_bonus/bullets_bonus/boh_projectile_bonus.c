/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boh_projectile_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:09:39 by root              #+#    #+#             */
/*   Updated: 2024/10/02 03:55:03 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"
#include "config_bonus.h"

void	boh_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet)
{
	if (anim == NULL || bullet == NULL)
		return ;
	t_sprite_init(bullet->sprite, &anim[IDX_TXTR_BOH_PROJ_LIVE], WIN_HEIGHT);
	bullet->use = entity_projectile_use;
	bullet->speed = BULLET_SPEED;
	bullet->damage = BOH_RANGE_DAMAGE;
	bullet->animation = &anim[IDX_TXTR_BOH_PROJ_DEATH];
}
