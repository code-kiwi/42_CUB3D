/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:03:22 by brappo            #+#    #+#             */
/*   Updated: 2024/07/01 19:03:51 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item_bonus.h"
#include "cub3d_bonus.h"
#include "entities_bonus.h"

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
	t_list	*aimed_entity;

	aimed_entity = ft_lstfind(game->entities, game->player.aimed_sprite,
			is_sprite_of_entity);
	if (aimed_entity == NULL)
		return ;
	damage_entity(game, aimed_entity->content, GUN_DAMAGE);
	game->player.aimed_sprite = NULL;
}
