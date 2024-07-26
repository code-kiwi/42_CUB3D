/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_attack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:10:55 by root              #+#    #+#             */
/*   Updated: 2024/07/26 10:00:06 by root             ###   ########.fr       */
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
}

bool	range_attack(t_entity *entity, t_game *game, size_t cooldown, \
	void (*bullet_init)(t_animation *, t_bullet *))
{
	if (entity == NULL || game == NULL || bullet_init == NULL
		|| entity->sprite == NULL)
		return (false);
	if (entity->cooldown > 0)
		return (true);
	set_animation(entity->sprite, entity->close_attack);
	entity->sprite->next_animation = entity->walk;
	entity->cooldown = cooldown;
	return (entity_shoot_bullet(game, entity, bullet_init));
}

void	entity_damage_player(t_game *game, t_sprite *entity_sprite)
{
	t_list	*entity;

	entity = ft_lstfind(game->entities, entity_sprite, is_sprite_of_entity);
	if (entity == NULL)
		return ;
	player_get_damage(game, ((t_entity *)entity->content)->close_damage);
}
