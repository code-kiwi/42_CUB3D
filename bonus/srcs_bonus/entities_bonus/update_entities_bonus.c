/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_entities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:06:13 by brappo            #+#    #+#             */
/*   Updated: 2024/07/22 13:05:17 by brappo           ###   ########.fr       */
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
		current = current->next;
		entity->update(game, entity, delta_time);
	}
}
