/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pain_elem_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/23 20:00:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

bool	pain_elem_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = pain_elem_update;
	entity->get_killed = entity_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_PAIN_ELEM_WALK];
	entity->pain = &animation[IDX_TXTR_PAIN_ELEM_PAIN];
	entity->death = &animation[IDX_TXTR_PAIN_ELEM_DEATH];
	entity->health_point = PAIN_ELEM_HEALTH_POINT;
	entity->speed = PAIN_ELEM_SPEED;
	entity->squared_radius = PAIN_ELEM_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_PAIN_ELEM_WALK], WIN_HEIGHT);
	return (true);
}
