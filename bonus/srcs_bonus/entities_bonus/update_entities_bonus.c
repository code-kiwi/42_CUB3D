/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:06:13 by brappo            #+#    #+#             */
/*   Updated: 2024/07/13 20:31:46 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "libft.h"
#include "cub3d_bonus.h"

void	update_entities(t_game *game, float delta_time)
{
	t_list		*current;
	t_entity	*entity;

	current = game->entities;
	update_entities_path(game);
	while (current)
	{
		entity = current->content;
		update_entity_position(entity, delta_time, game->entities,
			&game->map);
		entity->update(game, entity, delta_time);
		current = current->next;
	}
}
