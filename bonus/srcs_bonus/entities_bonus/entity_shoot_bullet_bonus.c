/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_shoot_bullet_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:39:12 by brappo            #+#    #+#             */
/*   Updated: 2024/07/19 11:50:41 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "bullets_bonus.h"

bool	entity_shoot_bullet(t_game *game, t_entity *entity,
	void (*use)(t_game *, t_bullet *))
{
	t_vector	direction;
	t_vector	position;

	direction.x = game->player.position.x - entity->sprite->position.x;
	direction.y = game->player.position.y - entity->sprite->position.y;
	normalize_vector(&direction);
	position.x = entity->sprite->position.x + direction.x;
	position.y = entity->sprite->position.y + direction.y;
	return (shoot_bullet(game, &position, &direction, use));
}