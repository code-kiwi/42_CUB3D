/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:06:13 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 21:57:40 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "libft.h"

static void	change_destination(t_entity *entity)
{
	t_list	*save;

	if (entity == NULL || entity->path == NULL)
		return ;
	save = entity->path;
	entity->path = entity->path->next;
	ft_lstdelone(save, free);
}

static void	update_entity(t_entity *entity, float delta_time, t_list *entities,
	t_map *map)
{
	t_mlx_coords	*next_pos;
	t_vector		*position;
	t_vector		move;
	float			move_length;

	if (entity->path == NULL)
		return ;
	next_pos = entity->path->content;
	position = &entity->sprite->position;
	move.x = next_pos->x + 0.5 - position->x;
	move.y = next_pos->y + 0.5 - position->y;
	move_length = get_vector_length(&move);
	mutlitply_vector(&move, entity->speed * delta_time / move_length);
	move_entity(entities, position, &move, map);
	if (move_length < entity->speed)
	{
		if (entity->is_path_circular)
			entity->path = entity->path->next;
		else
			change_destination(entity);
	}
}

void	update_entities(t_list *entities, float delta_time, t_map *map)
{
	t_list	*current;

	current = entities;
	while (current)
	{
		update_entity(current->content, delta_time, entities, map);
		current = current->next;
	}
}
