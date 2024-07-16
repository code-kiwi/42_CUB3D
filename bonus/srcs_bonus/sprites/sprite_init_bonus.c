/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:09:07 by brappo            #+#    #+#             */
/*   Updated: 2024/07/16 10:02:23 by brappo           ###   ########.fr       */
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

void	t_sprite_init(t_sprite *sprite, t_list *animation)
{
	if (sprite == NULL)
		return ;
	sprite->animation = animation;
	sprite->next_animation = animation;
	sprite->distance = 0;
	sprite->height = WIN_HEIGHT;
}

bool	init_sprites(t_game *game)
{
	t_list		*current;
	t_sprite	*sprite;

	if (!get_elem_into_list(&game->map, &game->sprites, IDS_MAP_SPRITE, \
			add_sprite))
		return (false);
	current = game->sprites;
	while (current)
	{
		sprite = current->content;
		t_sprite_init(sprite, game->textures[7]);
		current = current->next;
	}
	return (true);
}
