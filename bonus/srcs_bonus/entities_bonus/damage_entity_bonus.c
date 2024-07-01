/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damage_entity_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:53:40 by brappo            #+#    #+#             */
/*   Updated: 2024/07/01 19:07:54 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static int	equal(void *a, void *b)
{
	return (!(a == b));
}

static void	kill_entity(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return ;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
	ft_lst_remove_if(&game->sprites, game->player.aimed_sprite, equal, free);
}

void	damage_entity(t_game *game, t_entity *entity, size_t damage)
{
	if (entity->health_point <= damage)
		kill_entity(game, entity);
	else
		entity->health_point -= damage;
}
