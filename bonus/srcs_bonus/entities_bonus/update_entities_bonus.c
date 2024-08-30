/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:06:13 by brappo            #+#    #+#             */
/*   Updated: 2024/08/31 01:03:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

bool	update_entities(t_game *game, float delta_time)
{
	t_list		*current;
	t_entity	*entity;

	if (game == NULL)
		return (false);
	current = game->entities;
	update_entities_path(game);
	while (current)
	{
		entity = current->content;
		current = current->next;
		if (entity->cooldown > 0)
			entity->cooldown -= delta_time;
		if (entity->cooldown_from_player > 0)
		{
			entity->sprite->locked = true;
			entity->cooldown_from_player -= delta_time;
			continue ;
		}
		else
			entity->sprite->locked = false;
		if (!entity->update(game, entity, delta_time))
			return (false);
	}
	return (true);
}
