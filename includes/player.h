/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:04:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 12:54:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
#define PLAYER_H

# include "vector.h"

# define FOV_ANGLE_DEFAULT 3.14159265358 / 3

typedef struct s_player t_player;

enum e_direction
{
	WALK_UP,
	WALK_LEFT,
	WALK_DOWN,
	WALK_RIGHT,
	NONE
};

struct s_player
{
	float				fov_angle;
	t_vector			position;
	float				orientation;
	enum e_direction	walk_dir;
	int					turn_direction;
	float				move_speed;
	float				rotation_speed;
};

// t_player functions
bool    t_player_init(t_player *player, t_map *map);

#endif