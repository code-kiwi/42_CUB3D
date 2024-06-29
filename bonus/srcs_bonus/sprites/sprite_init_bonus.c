/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:09:07 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 12:59:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"
#include "libft.h"
#include "cub3d_bonus.h"
#include "map_bonus.h"

static bool	add_sprite(t_list **sprites, float x, float y)
{
	t_list		*new_node;
	t_sprite	*new_sprite;

	new_sprite = ft_calloc(1, sizeof(t_sprite));
	if (new_sprite == NULL)
		return (false);
	new_sprite->position.x = x;
	new_sprite->position.y = y;
	new_node = ft_lstnew(new_sprite);
	if (new_node == NULL)
	{
		free(new_sprite);
		return (false);
	}
	ft_lstadd_front(sprites, new_node);
	return (true);
}

bool	sprite_init(t_game *game)
{
	t_list		*current;
	t_sprite	*sprite;

	if (!get_elemn_into_list(&game->map, &game->sprites, ID_SPRITE, add_sprite))
		return (false);
	current = game->sprites;
	while (current)
	{
		sprite = current->content;
		sprite->animation = game->textures[7];
		sprite->distance = 0;
		sprite->height = WIN_HEIGHT;
		current = current->next;
	}
	return (true);
}
