/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:09:22 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/29 23:29:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONS_BONUS_H
# define WEAPONS_BONUS_H

# include <sys/types.h>
# include <stdbool.h>

# include "mlx_api_bonus.h"

# define WEAPONS_H_RATIO				0.5f
# define NB_TOT_WEAPONS					3
# define IDX_W1_HAND					0
# define IDX_W2_PISTOL					1
# define IDX_W3_CHAINGUN				2

# define W1_HAND_LOAD_CAPACITY			0
# define W1_HAND_INITIAL_USES			0
# define W1_HAND_DAMAGES				5
# define W1_HAND_RANGE					1.05f
# define W1_HAND_COOLDOWN_EFFECT		0

# define W2_PISTOL_LOAD_CAPACITY		5
# define W2_PISTOL_INITIAL_USES			5
# define W2_PISTOL_DAMAGES				3
# define W2_PISTOL_RANGE				10.0f
# define W2_PISTOL_COOLDOWN_EFFECT		0.6f

# define W3_CHAINGUN_LOAD_CAPACITY		100
# define W3_CHAINGUN_INITIAL_USES		50
# define W3_CHAINGUN_DAMAGES			1
# define W3_CHAINGUN_RANGE				5.0f
# define W3_CHAINGUN_BULLET_SPEED		25
# define W3_CHAINGUN_COOLDOWN_EFFECT	0

typedef struct s_weapon		t_weapon;
typedef struct s_list		t_list;
typedef struct s_game		t_game;
typedef struct s_bullet		t_bullet;
typedef struct s_animation	t_animation;

struct s_weapon
{
	t_image			*curr_frame;
	t_list			*curr_frame_link;
	t_image			*frame_default;
	t_list			*frames_action;
	t_image			*target;
	float			animation_update;
	size_t			load_capacity;
	size_t			remaining_use;
	size_t			damage;
	float			range;
	float			cooldown_curr;
	float			cooldown_effect;
	bool			is_limited;
	bool			is_use_continuous;
	bool			using;
	int				bullet_speed;
	float			bullet_cooldown_effect;
	t_animation		*bullet_live_anim;
	t_animation		*bullet_death_anim;
	t_mlx_coords	coords;
	t_mlx_coords	size;
	t_mlx_coords	target_coords;
	t_mlx_coords	target_size;
	void			(*action)(t_weapon *, t_game *);
	void			(*bullet_init)(t_bullet *, t_weapon *);
	void			(*bullet_use)(t_game *game, t_bullet *);
};

// Weapon functions
bool	init_weapons(t_game *game);
bool	init_resize_imgs(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx);
void	init_all_weapon_positions(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx);
void	update_weapon(t_weapon *weapon, t_game *game);
void	set_weapon_position(t_weapon *weapon, t_mlx *mlx);
void	set_weapon_target_position(t_weapon *weapon, t_mlx *mlx);
void	use_weapon(t_weapon *weapon, t_game *game);
void	stop_weapon(t_weapon *weapon);
void	weapon_update_cooldown(t_weapon *weapon, float delta_time);

// Weapon callbacks
void	use_weapon_hand(t_weapon *weapon, t_game *game);
void	use_weapon_no_bullet(t_weapon *weapon, t_game *game);
void	use_weapon_bullet(t_weapon *weapon, t_game *game);

#endif
