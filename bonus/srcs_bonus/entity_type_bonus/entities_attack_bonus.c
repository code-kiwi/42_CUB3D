/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_attack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:55 by root              #+#    #+#             */
/*   Updated: 2024/09/01 10:47:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

void	close_attack(t_entity *entity, t_game *game, size_t cooldown)
{
	if (entity == NULL || game == NULL)
		return ;
	if (entity->cooldown > 0)
		return ;
	set_animation(entity->sprite, entity->close_attack);
	entity->sprite->next_animation = entity->walk;
	entity->cooldown = cooldown;
	entity->close_attack->on_end = entity_damage_player;
}

void	range_attack(t_entity *entity, t_game *game, size_t cooldown)
{
	if (entity == NULL || game == NULL || entity->sprite == NULL)
		return ;
	if (entity->cooldown > 0)
		return ;
	set_animation(entity->sprite, entity->range_attack);
	entity->sprite->next_animation = entity->walk;
	entity->cooldown = cooldown;
	entity->range_attack->on_end = entity_shoot_bullet;
}

bool	entity_damage_player(t_game *game, t_sprite *entity_sprite)
{
	t_list	*entity;

	entity = ft_lstfind(game->entities, entity_sprite, is_sprite_of_entity);
	if (entity == NULL)
		return (false);
	player_get_damage(game, ((t_entity *)entity->content)->close_damage);
	return (true);
}
