/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entities_path_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:05:48 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 15:22:28 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

bool	can_see(t_vector *position, t_vector *point, t_game *game)
{
	t_ray		ray;
	float		distance;
	float		ray_length;

	ray.slope.x = point->x - position->x;
	ray.slope.y = point->y - position->y;
	distance = get_vector_length(&ray.slope);
	ray.slope.x /= distance;
	ray.slope.y /= distance;
	ray_length = raycast(*position, game, &ray);
	return (ray_length >= distance);
}

bool	update_entities_path(t_game *game)
{
	t_list		*current;
	t_entity	*entity;

	if (game == NULL)
		return ;
	current = game->entities;
	while (current)
	{
		entity = current->content;
		printf("can see : %s\n", can_see(&entity->sprite->position, &game->player.position, game) ? "true" : "false");
		current = current->next;
	}
	return (true);
}