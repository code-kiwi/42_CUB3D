/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_destroy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:33:54 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/21 16:59:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d_bonus.h"
#include "sprite_bonus.h"

void	destroy_sprites(t_sprite ***sprites_ptr, size_t sprites_count)
{
	size_t		index;
	t_sprite	**sprites;

	if (sprites_ptr == NULL)
		return ;
	sprites = *sprites_ptr;
	index = 0;
	while (index < sprites_count)
	{
		free(sprites[index]);
		index++;
	}
	free(sprites);
	*sprites_ptr = NULL;
}
