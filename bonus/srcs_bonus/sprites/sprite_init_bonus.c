/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:09:07 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 14:56:35 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite_bonus.h"
#include "libft.h"
#include "cub3d_bonus.h"

bool	sprite_init(t_game *game)
{
	t_list		*current;
	t_sprite	*sprite;

	if (!get_sprites(&game->map, &game->sprites))
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
