/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lost_soul_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:26:59 by brappo            #+#    #+#             */
/*   Updated: 2024/08/26 08:16:40 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

bool	lost_soul_update(t_game *game, t_entity *entity, float delta_time)
{
	t_player	*player;
	float		distance;
	t_sprite	*sprite;

	if (entity->cooldown > 0)
		entity->cooldown -= delta_time;
	sprite = entity->sprite;
	player = &game->player;
	distance = get_distance(&sprite->position, &player->position);
	sprite->animate = true;
	if (distance < LOST_SOUL_RANGE)
		entity->get_killed(game, entity);
	else
		update_entity_position(entity, delta_time, game->entities, &game->map);
	return (true);
}

static void	lost_soul_get_killed(t_game *game, t_entity *entity)
{
	if (game == NULL || entity == NULL || game->entities == NULL)
		return ;
	if (game->last_entity_updated->content == entity)
		game->last_entity_updated = game->last_entity_updated->next;
	set_animation(entity->sprite, &game->anim[IDX_TXTR_LOST_SOUL_DEATH]);
	entity->sprite->next_animation = NULL;
	ft_lst_remove_if(&game->entities, entity, equal, t_entity_destroy);
}

void	lost_soul_init(t_entity *entity, t_animation animation[MAP_NB_IDS])
{
	entity->update = lost_soul_update;
	entity->get_killed = lost_soul_get_killed;
	entity->get_damage = entity_get_damage;
	entity->get_chainsawed = entity_get_chainsawed;
	entity->walk = &animation[IDX_TXTR_LOST_SOUL_WALK];
	entity->pain = NULL;
	entity->death = &animation[IDX_TXTR_LOST_SOUL_DEATH];
	entity->close_attack = NULL;
	entity->range_attack = NULL;
	entity->health_point = 0;
	entity->speed = LOST_SOUL_SPEED;
	entity->squared_radius = LOST_SOUL_SQUARED_RADIUS;
	entity->type = NULL;
	t_sprite_init(entity->sprite, &animation[IDX_TXTR_LOST_SOUL_WALK],
		WIN_HEIGHT);
	entity->sprite->height = WIN_HEIGHT * LOST_SOUL_HEIGHT_RATIO;
}
