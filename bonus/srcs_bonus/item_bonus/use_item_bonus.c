/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_item_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:03:22 by brappo            #+#    #+#             */
/*   Updated: 2024/07/22 10:58:36 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item_bonus.h"
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

void	use_gun(t_game *game)
{
	t_list		*aimed_entity;
	t_entity	*entity;
	t_player	*player;

	if (game == NULL)
		return ;
	player = &game->player;
	player_shoot(game);
	aimed_entity = ft_lstfind(game->entities, game->player.aimed_sprite,
			is_sprite_of_entity);
	if (aimed_entity == NULL)
		return ;
	entity = aimed_entity->content;
	if (entity == NULL)
		return ;
	entity->get_damage(game, entity, GUN_DAMAGE);
	player->aimed_sprite = NULL;
}

void	use_item(t_game *game)
{
	t_item	*item_in_hand;

	if (game == NULL)
		return ;
	item_in_hand = game->player.item_in_hand;
	if (item_in_hand == NULL || item_in_hand->remaining_usage == 0)
		return ;
	item_in_hand->use_item(game);
	if (item_in_hand->remaining_usage != -1)
		item_in_hand->remaining_usage--;
}
