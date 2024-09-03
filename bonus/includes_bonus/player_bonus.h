/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:04:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 09:25:38 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_BONUS_H
# define PLAYER_BONUS_H

# include "vector_bonus.h"
# include "mlx_api_bonus.h"
# include "weapons_bonus.h"

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
# define PLAYER_HEALTH_POINT			25
# define PLAYER_RADIUS					0.3

# define PLAYER_WEAPON_V_MOVE_UPDATE	0.02f
# define PLAYER_WEAPON_H_MOVE_UPDATE	0.04f
# define PLAYER_WEAPON_V_OFFSET_RATIO	0.06f
# define PLAYER_WEAPON_H_OFFSET_STEP	10
# define PLAYER_WEAPON_H_OFFSET_MAX		50

# define MAX_Y_ROTATION_RATIO			0.7

# define PLAYER_MIN_DIST_TO_WALL		0.05f

typedef struct s_game				t_game;
typedef struct s_player				t_player;
typedef struct s_player_weapon		t_player_weapon;
typedef struct s_map				t_map;
typedef struct s_ray				t_ray;
typedef struct s_list				t_list;
typedef struct s_door				t_door;
typedef struct s_sprite				t_sprite;
typedef enum e_player_weapon_state	t_weapon_state;

enum e_player_weapon_state
{
	WEAPON_STATE_IDLE,
	WEAPON_STATE_HOLSTERING,
	WEAPON_STATE_DRAWING,
	WEAPON_STATE_USING
};

struct s_player_weapon
{
	t_weapon		*weapons[NB_TOT_WEAPONS + 1];
	size_t			curr_weapon_index;
	t_weapon		*curr_weapon;
	t_mlx_coords	draw_offset;
	size_t			next_weapon_index;
	t_weapon_state	weapon_state;
	float			frame_update_delta;
	float			frame_update_delta_h_move;
	int				draw_offset_sign;
	int				switch_vert_offset;
};

struct s_player
{
	float			fov_angle;
	t_vector		position;
	t_vector		orientation;
	bool			walk_direction[4];
	float			move_speed[4];
	t_vector		rotation_speed;
	float			leftmost_angle;
	float			pixel_by_angle;
	t_ray			*look_ray;
	t_door			*last_door_seen;
	t_sprite		*aimed_sprite;
	size_t			health_point;
	bool			is_walking;
	bool			is_dead;
	t_player_weapon	weapon_info;
};

// t_player functions
bool	t_player_init(t_player *player, t_map *map, t_game *game);
void	update_player(t_game *game, float delta_time);
void	move_player(t_list *entities, t_vector *position, t_vector *move, \
			t_map *map);
void	update_player_weapon(t_player_weapon *weapon_info, \
			bool is_player_walking, t_game *game, float delta_time);
void	player_get_damage(t_game *game, size_t damage);
void	draw_player(t_game *game, t_player_weapon *weapon_info);

// Weapons utils
bool	init_player_weapons(t_game *game, t_player_weapon *weapon_info);
void	player_select_weapon(t_player_weapon *weapon_info, int index);
void	player_weapon_use(t_player_weapon *weapon_info, t_game *game);
void	player_weapon_use_stop(t_player_weapon *weapon_info, t_game *game);

#endif
