/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:04:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/22 11:26:08 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "vector_bonus.h"
# include "mlx_api_bonus.h"

# define PLAYER_POS_ORDERED				"ENWS"
# define FOV_ANGLE_DEFAULT				1.05
# define FRONT 							0
# define LEFT 							1
# define BACK 							2
# define RIGHT 							3

# define PLAYER_SPEED_FORWARD			5
# define PLAYER_SPEED_BACKWARD			3
# define PLAYER_SPEED_LEFT				3
# define PLAYER_SPEED_RIGHT				3
# define PLAYER_INTERACTION_DISTANCE	1.5
# define PLAYER_HEALTH_POINT			6

typedef struct s_game			t_game;
typedef struct s_player			t_player;
typedef struct s_map			t_map;
typedef struct s_ray			t_ray;
typedef struct s_list			t_list;
typedef struct s_door			t_door;
typedef struct s_sprite			t_sprite;

struct s_player
{
	float				fov_angle;
	t_vector			position;
	float				orientation;
	bool				is_walking[4];
	float				move_speed[4];
	float				rotation_speed;
	float				leftmost_angle;
	float				pixel_by_angle;
	t_ray				*look_ray;
	t_door				*last_door_seen;
	t_sprite			*aimed_sprite;
	size_t				health_point;
};

// t_player functions
bool	t_player_init(t_player *player, t_map *map, t_game *game);
void	destroy_player(t_player *player, void *mlx_ptr);
void	player_shoot(t_game *game);
void	update_player(t_player *player, t_map *map, float delta_time,
			t_list *entities);
void	player_get_damage(t_game *game, size_t damage);

#endif