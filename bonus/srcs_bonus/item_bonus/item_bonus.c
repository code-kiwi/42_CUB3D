/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:03:22 by brappo            #+#    #+#             */
/*   Updated: 2024/07/01 15:34:22 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item_bonus.h"
#include "cub3d_bonus.h"
#include "entities_bonus.h"

int	is_sprite_of_entity(void *entity_void, void *sprite_void)
{
	t_entity	*entity;
	t_sprite	*sprite;

	entity = entity_void;
	sprite = sprite_void;
	return (!(entity->sprite == sprite));
}

int	equal(void *a, void *b)
{
	return (!(a == b));
}

void	use_gun(t_game *game)
{
	t_list	*aimed_entity;

	aimed_entity = ft_lstfind(game->entities, game->player.aimed_sprite,
			is_sprite_of_entity);
	if (aimed_entity != NULL)
	{
		ft_lst_remove_if(&game->entities, aimed_entity->content, equal,
			t_entity_destroy);
	}
	ft_lst_remove_if(&game->sprites, game->player.aimed_sprite, equal, free);
	game->player.aimed_sprite = NULL;
}
