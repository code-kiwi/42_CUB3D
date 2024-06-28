/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:04:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/27 20:14:20 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "vector_bonus.h"

# define PLAYER_POS_ORDERED				"ENWS"
# define FOV_ANGLE_DEFAULT				1.047197551 
# define FRONT 							0
# define LEFT 							1
# define BACK 							2
# define RIGHT 							3

# define PLAYER_SPEED_FORWARD			5
# define PLAYER_SPEED_BACKWARD			3
# define PLAYER_SPEED_LEFT				3
# define PLAYER_SPEED_RIGHT				3
# define PLAYER_SPEED_ROTATION			1.570796327
# define PLAYER_INTERACTION_DISTANCE	1.5

typedef struct s_player	t_player;
typedef struct s_map	t_map;
typedef struct s_ray	t_ray;

struct s_player
{
	float		fov_angle;
	t_vector	position;
	float		orientation;
	bool		is_walking[4];
	int			turn_direction[2];
	float		move_speed[4];
	float		rotation_speed;
	float		leftmost_angle;
	float		pixel_by_angle;
	t_ray		*look_ray;
};

// t_player functions
bool	t_player_init(t_player *player, t_map *map, t_game *game);
void	update_player(t_player *player, t_map *map, float delta_time);

#endif
