/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:04:34 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/10 12:18:37 by mhotting         ###   ########.fr       */
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

# define PLAYER_TEXTURE_FILE			"./assets/test_textures/hands.xpm"
# define PLAYER_TEXTURE_WIDTH			300
# define PLAYER_TEXTURE_HEIGHT			400
# define PLAYER_ANIMATION_UPDATE		0.1
# define PLAYER_TARGET_TEXTURE_FILE		"./assets/test_textures/target.xpm"
# define PLAYER_TEXTURE_X_OFFSET		200

typedef struct s_game			t_game;
typedef struct s_player			t_player;
typedef struct s_player_display	t_player_display;
typedef struct s_map			t_map;
typedef struct s_ray			t_ray;
typedef struct s_list			t_list;
typedef struct s_door			t_door;

struct s_player_display
{
	t_list			*frame_curr;
	t_list			*frames;
	t_mlx_coords	coords;
	t_mlx_coords	size;
	float			frame_update_delta;
	t_mlx_coords	target_coords;
	t_mlx_coords	target_size;
	t_image			target_texture;
};

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
	t_player_display	display;
};

// t_player functions
bool	t_player_init(t_player *player, t_map *map, t_game *game);
bool	t_player_init_display(t_player_display *display, void *mlx_ptr);
void	player_shoot(t_game *game);
void	destroy_player(t_player *player, void *mlx_ptr);
void	player_shoot(t_game *game);
void	update_player(t_player *player, t_map *map, float delta_time,
			t_list *entities);

#endif
