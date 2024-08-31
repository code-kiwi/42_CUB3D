/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:07:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/31 14:36:42 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

void	use_weapon_no_bullet(t_weapon *weapon, t_game *game)
{
	t_list		*aimed_entity;
	t_entity	*entity;
	t_player	*player;

	if (game == NULL || weapon == NULL
		|| (weapon->is_limited && weapon->remaining_use == 0))
		return ;
	weapon->remaining_use--;
	player = &game->player;
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

void	use_weapon_bullet(t_weapon *weapon, t_game *game)
{
	t_player	*player;
	t_vector	direction;
	t_vector	position;

	if (game == NULL || weapon == NULL
		|| (weapon->is_limited && weapon->remaining_use == 0))
		return ;
	weapon->remaining_use--;
	player = &game->player;
	t_vector_get_slope(&direction, player->orientation.x);
	direction.y *= -1;
	position.x = player->position.x + direction.x;
	position.y = player->position.y + direction.y;
	shoot_bullet_from_player(game, &player->position, &direction, \
		weapon->bullet_init);
}

void	use_weapon_hand(t_weapon *weapon, t_game *game)
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
