/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide_entity_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:22:48 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 17:32:47 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"

bool	collide_entity(t_list *entities, t_vector *position)
{
	t_list		*current;
	t_entity	*entity;

	if (entities == NULL || position == NULL)
		return (false);
	current = entities;
	while (current)
	{
		entity = current->content;
		if (&entity->sprite->position != position
			&& get_squared_distance(&entity->sprite->position, position) <= \
				entity->squared_radius)
		{
			return (true);
		}
		current = current->next;
	}
	return (false);
}
