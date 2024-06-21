/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:11:53 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/21 15:31:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# include <stdlib.h>

# include "vector_bonus.h"

typedef struct s_sprite	t_sprite;
typedef struct s_image	t_image;
typedef struct s_map	t_map;

struct	s_sprite
{
	t_vector	position;
	float		distance;
	t_image		*texture;
};

// Sprites functions
void		get_sprites_distances(t_sprite **sprites, t_vector *pos,
				size_t length);
void		get_sprites(t_map *map, size_t sprites_count, t_sprite **sprites);
size_t		count_sprites(t_map *map);
t_sprite	**alloc_sprites(size_t sprites_count);
void		sort_sprites(t_sprite **sprites, size_t length);

#endif