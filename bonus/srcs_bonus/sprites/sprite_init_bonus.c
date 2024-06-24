/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:09:07 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 11:14:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"
#include "cub3d_bonus.h"

#include <errno.h>

bool	sprite_init(t_game *game)
{
	t_list		*current;
	t_sprite	*sprite;

	game->sprites = get_sprites(&game->map);
	if (game->sprites == NULL)
		return (errno == 0);
	current = game->sprites;
	while (current)
	{
		sprite = current->content;
		sprite->texture = &game->textures[7];
		sprite->distance = 0;
		current = current->next;
	}
	return (true);
}
