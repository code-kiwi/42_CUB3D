/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:11:53 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/17 10:34:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# include <stdlib.h>

# include "vector_bonus.h"
# include "libft.h"

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
	t_list		*next_animation;
	size_t		height;
	float		frame_update_delta;
	bool		animate;
};

// Sprites functions
void		destroy_sprites(t_sprite ***sprites_ptr, size_t sprites_count);
void		get_sprites_distances(t_list *sprites, t_vector *pos);
float		compare_sprite_distance(void *a, void *b);
void		t_sprite_init(t_sprite *sprite, t_list *animation, size_t height);
bool		init_sprites(t_game *game);
void		*add_sprite(t_game *game, float x, float y, char id);

#endif
