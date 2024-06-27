/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:11:53 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/27 20:14:28 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# include <stdlib.h>

# include "vector_bonus.h"
# include "libft.h"

# define TEXTURE_SIZE			64

typedef struct s_game	t_game;
typedef struct s_sprite	t_sprite;
typedef struct s_image	t_image;
typedef struct s_map	t_map;
typedef struct s_list	t_list;

struct	s_sprite
{
	t_vector	position;
	float		distance;
	t_list		*animation;
	size_t		height;
};

// Sprites functions
void		destroy_sprites(t_sprite ***sprites_ptr, size_t sprites_count);
bool		get_sprites(t_map *map, t_list **sprites);
void		get_sprites_distances(t_list *sprites, t_vector *pos);
int			compare_sprite_distance(void *a, void *b);
bool		sprite_init(t_game *game);

#endif
