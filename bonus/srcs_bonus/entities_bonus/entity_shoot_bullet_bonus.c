/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_shoot_bullet_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:39:12 by brappo            #+#    #+#             */
/*   Updated: 2024/07/22 11:00:10 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

#include <math.h>

bool	entity_shoot_bullet(t_game *game, t_entity *entity,
	void (*bullet_init)(t_list *textures[MAP_NB_IDS], t_bullet *))
{
	t_vector	direction;
	t_vector	position;
	float		radius;

	direction.x = game->player.position.x - entity->sprite->position.x;
	direction.y = game->player.position.y - entity->sprite->position.y;
	normalize_vector(&direction);
	radius = sqrt(entity->squared_radius) + 0.1f;
	position.x = entity->sprite->position.x + direction.x * radius;
	position.y = entity->sprite->position.y + direction.y * radius;
	return (shoot_bullet(game, &position, &direction, bullet_init));
}
