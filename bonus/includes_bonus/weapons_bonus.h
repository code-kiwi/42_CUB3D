/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapons_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:09:22 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/23 13:49:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPONS_BONUS_H
# define WEAPONS_BONUS_H

# include <sys/types.h>
# include <stdbool.h>

# include "mlx_api_bonus.h"

# define WEAPONS_H_RATIO	0.5f
# define NB_TOT_WEAPONS		2
# define IDX_W1_HAND		0
# define IDX_W2_PISTOL		1

typedef struct s_weapon	t_weapon;
typedef struct s_list	t_list;
typedef struct s_game	t_game;

struct s_weapon
{
	t_image			*curr_frame;
	t_list			*curr_frame_link;
	t_image			*frame_default;
	t_list			*frames_action;
	t_list			*frames_bullet;
	t_image			*target;
	size_t			num_loads;
	size_t			load_capacity;
	size_t			remaining_use;
	size_t			damage;
	float			range;
	bool			is_limited;
	bool			is_use_continuous;
	bool			active;
	char			id;
	t_mlx_coords	coords;
	t_mlx_coords	size;
	t_mlx_coords	target_coords;
	t_mlx_coords	target_size;
	void			(*action)(t_weapon *, t_game *);
};

// Weapon functions
bool	init_weapons(t_game *game);
bool	init_resize_imgs(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx);
void	init_all_weapon_positions(t_weapon weapons[NB_TOT_WEAPONS], t_mlx *mlx);
void	update_weapon(t_weapon *weapon, t_game *game);
void	set_weapon_position(t_weapon *weapon, t_mlx *mlx);
void	set_weapon_target_position(t_weapon *weapon, t_mlx *mlx);
void	use_weapon(t_weapon *weapon, t_game *game);

// Weapon callbacks
void	use_gun_classic(t_weapon *weapon, t_game *game);
void	use_weapon_no_bullet(t_weapon *weapon, t_game *game);

#endif
