/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullets_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:42:07 by brappo            #+#    #+#             */
/*   Updated: 2024/08/29 16:54:13 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETS_BONUS_H
# define BULLETS_BONUS_H

# include "vector_bonus.h"
# include "cub3d_bonus.h"

# define BULLET_SPEED				5
# define BULLET_HEIGHT_WINDOW_RATIO	0.25

typedef struct s_bullet	t_bullet;

struct	s_bullet
{
	t_vector	move;
	void		(*use)(t_game *, t_bullet *);
	t_sprite	*sprite;
	float		speed;
	int			damage;
	bool		player_protected;
	t_animation	*animation;	
};

void	update_bullets(t_game *game, float delta_time);
bool	shoot_bullet_from_entity(t_game *game, t_vector *position, \
			t_vector *direction, \
			void (*init_bullet)(t_animation anim[MAP_NB_IDS], t_bullet *));
bool	shoot_bullet_from_player(t_game *game, t_vector *position, \
			t_vector *direction, void (*init_bullet)(t_bullet *, t_weapon *));
void	caco_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet);
void	imp_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet);
void	boh_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet);
void	rocket_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet);
void	manc_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet);
void	rev_proj_init(t_animation anim[MAP_NB_IDS], t_bullet *bullet);
void	entity_projectile_use(t_game *game, t_bullet *bullet);
void	player_basic_projectile_use(t_game *game, t_bullet *bullet);

void	player_gun_proj_init(t_bullet *bullet, t_weapon *weapon);

#endif
