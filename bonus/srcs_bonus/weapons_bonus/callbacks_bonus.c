/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:07:17 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/31 22:35:20 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "entities_bonus.h"
#include "bullets_bonus.h"

static void	damage_target_entity(t_game *game, t_weapon *weapon, bool chainsaw)
{
	t_list		*aimed_entity;
	t_entity	*entity;
	t_player	*player;

	player = &game->player;
	aimed_entity = ft_lstfind(game->entities, player->aimed_sprite, \
		is_sprite_of_entity);
	if (aimed_entity == NULL)
		return ;
	entity = aimed_entity->content;
	if (entity == NULL || entity->sprite->distance > weapon->range)
		return ;
	if (chainsaw)
		entity->get_chainsawed(game, entity, weapon->damage);
	else
		entity->get_damage(game, entity, weapon->damage);
	player->aimed_sprite = NULL;
}

void	use_weapon_no_bullet(t_weapon *weapon, t_game *game)
{
	if (game == NULL || weapon == NULL
		|| (weapon->is_limited && weapon->remaining_use == 0))
		return ;
	weapon->remaining_use--;
	damage_target_entity(game, weapon, false);
}

void	use_weapon_hand(t_weapon *weapon, t_game *game)
{
	if (weapon == NULL || game == NULL)
		return ;
	damage_target_entity(game, weapon, false);
}

void	use_weapon_chainsaw(t_weapon *weapon, t_game *game)
{
	if (weapon == NULL || game == NULL)
		return ;
	damage_target_entity(game, weapon, true);
}

void	use_weapon_bullet(t_weapon *weapon, t_game *game)
{
	t_player	*player;
	t_vector	direction;

	if (game == NULL || weapon == NULL
		|| (weapon->is_limited && weapon->remaining_use == 0))
		return ;
	weapon->remaining_use--;
	player = &game->player;
	t_vector_get_slope(&direction, player->orientation.x);
	direction.y *= -1;
	shoot_bullet_from_player(game, &player->position, &direction, \
		weapon->bullet_init);
}
