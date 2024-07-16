/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullets_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:42:07 by brappo            #+#    #+#             */
/*   Updated: 2024/07/16 15:08:17 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETS_BONUS_H
# define BULLETS_BONUS_H

# include "vector_bonus.h"
# include "cub3d_bonus.h"

# define BULLET_SPEED	2

typedef struct s_bullet	t_bullet;

struct	s_bullet
{
	t_vector	position;
	t_vector	normalized_direction;
	void		(*use)(t_game *game);
};

#endif // !BULLETS_BONUS_H
