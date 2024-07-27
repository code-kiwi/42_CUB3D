/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:06:13 by brappo            #+#    #+#             */
/*   Updated: 2024/07/27 19:04:50 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "libft.h"
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
		if (!entity->update(game, entity, delta_time))
			return (false);
	}
	return (true);
}
