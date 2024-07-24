/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_attack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:55 by root              #+#    #+#             */
/*   Updated: 2024/07/24 10:12:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "cub3d_bonus.h"

void	close_attack(t_entity *entity, t_game *game, size_t cooldown, \
	size_t damage)
{
	if (entity->cooldown > 0)
		return ;
	set_animation(entity->sprite, entity->close_attack);
	entity->sprite->next_animation = entity->walk;
	entity->cooldown = cooldown;
	player_get_damage(game, damage);
}

bool	range_attack(t_entity *entity, t_game *game, size_t cooldown, \
	void (*bullet_init)(t_animation *, t_bullet *))
{
	if (entity->cooldown > 0)
		return (true);
	set_animation(entity->sprite, entity->close_attack);
	entity->sprite->next_animation = entity->walk;
	entity->cooldown = cooldown;
	return (entity_shoot_bullet(game, entity, bullet_init));
}