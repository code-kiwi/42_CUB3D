/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demon_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/07/16 11:53:19 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

static bool	demon_update(t_game *game, t_entity *entity, float delta_time)
{
	update_entity_position(entity, delta_time, game->entities, &game->map);
	return (true);
}

static bool	demon_get_killed(t_game *game, t_entity *entity)
{
	return (true);
}

static bool	demon_get_damage(t_game *game, t_entity *entity, size_t damage)
{
	damage_entity(game, entity, damage);
	return (true);
}

static bool	demon_get_chainsawed(t_game *game, t_entity *entity)
{
	return (true);
}

bool	demon_init(t_entity *entity, t_list *textures[MAP_NB_IDS])
{
	entity->update = demon_update;
	entity->get_killed = demon_get_killed;
	entity->get_damage = demon_get_damage;
	entity->get_chainsawed = demon_get_chainsawed;
	entity->type = ft_calloc(1, sizeof(t_demon));
	t_sprite_init(entity->sprite, textures[8]);
	return (entity->type != NULL);
}
