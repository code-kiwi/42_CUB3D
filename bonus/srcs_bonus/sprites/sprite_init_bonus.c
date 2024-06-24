/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:33:54 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 14:13:59 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "sprite_bonus.h"
#include "libft.h"

bool	init_sprites(t_game *game)
{
	size_t	index;

	index = 0;
	game->sprites_count = count_sprites(&game->map);
	if (game->sprites_count != 0)
	{
		game->sprites = alloc_sprites(game->sprites_count);
		if (game->sprites == NULL)
			return (false);
		get_sprites(&game->map, game->sprites_count, game->sprites);
	}
	else
		game->sprites = NULL;
	while (index < game->sprites_count)
	{
		game->sprites[index]->animation = game->textures[6];
		index++;
	}
	return (true);
}
