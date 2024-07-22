/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:35:15 by brappo            #+#    #+#             */
/*   Updated: 2024/07/22 22:23:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_BONUS_H
# define ANIMATION_BONUS_H

# include <stdbool.h>

typedef struct s_list		t_list;
typedef struct s_image		t_image;
typedef struct s_animation	t_animation;
typedef struct s_game		t_game;
typedef struct s_sprite		t_sprite;
typedef struct s_mlx_coords	t_mlx_coords;

# define ANIMATION_UPDATE	0.1

struct s_animation
{
	t_list	*textures;
	size_t	wait;
	bool	(*on_end)(t_game *, t_sprite *);
};

void	destroy_animation(t_animation *anim, void *mlx_ptr);
t_list	*create_animation(t_image *texture, t_mlx_coords *size, void *mlx_ptr,
			char *texture_name);
void	update_animations(t_game *game, float delta_time);

#endif
