/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:07:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/23 14:09:03 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

static int	is_sprite_of_entity(void *entity_void, void *sprite_void)
{
	t_entity	*entity;
	t_sprite	*sprite;

	entity = entity_void;
	sprite = sprite_void;
	return (!(entity->sprite == sprite));
}

void	use_gun_classic(t_weapon *weapon, t_game *game)
{
	t_list		*aimed_entity;
	t_entity	*entity;
	t_player	*player;
	t_vector	direction;

	if (game == NULL)
		return ;
	player = &game->player;
	t_vector_get_slope(&direction, player->orientation);
	direction.y *= -1;
	shoot_bullet(game, &player->position, &direction, imp_projectile_use);
	aimed_entity = ft_lstfind(game->entities, game->player.aimed_sprite, \
		is_sprite_of_entity);
	if (aimed_entity == NULL)
		return ;
	entity = aimed_entity->content;
	if (entity == NULL || entity->sprite->distance > weapon->range)
		return ;
	entity->get_damage(game, entity, weapon->damage);
	player->aimed_sprite = NULL;
}

void	use_weapon_no_bullet(t_weapon *weapon, t_game *game)
{
	t_list		*aimed_entity;
	t_entity	*entity;
	t_player	*player;

	if (game == NULL)
		return ;
	player = &game->player;
	aimed_entity = ft_lstfind(game->entities, player->aimed_sprite, \
		is_sprite_of_entity);
	if (aimed_entity == NULL)
		return ;
	entity = aimed_entity->content;
	if (entity == NULL || entity->sprite->distance > weapon->range)
		return ;
	entity->get_damage(game, entity, weapon->damage);
	player->aimed_sprite = NULL;
}
