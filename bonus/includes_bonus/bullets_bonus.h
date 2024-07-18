/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullets_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:42:07 by brappo            #+#    #+#             */
/*   Updated: 2024/07/17 12:03:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETS_BONUS_H
# define BULLETS_BONUS_H

# include "vector_bonus.h"
# include "cub3d_bonus.h"

# define BULLET_SPEED	5

typedef struct s_bullet	t_bullet;

struct	s_bullet
{
	t_vector	move;
	void		(*use)(t_game *, t_bullet *);
	t_sprite	*sprite;
};

void	update_bullets(t_game *game, float delta_time);
bool	shoot_bullet(t_game *game, t_vector *position, t_vector *direction,
			void (*use)(t_game *, t_bullet *));
void	imp_projectile_use(t_game *game, t_bullet *bullet);

#endif // !BULLETS_BONUS_H