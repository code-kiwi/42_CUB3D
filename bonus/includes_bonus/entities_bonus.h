/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:07:32 by brappo            #+#    #+#             */
/*   Updated: 2024/07/19 15:51:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_BONUS_H
# define ENTITIES_BONUS_H

# include "sprite_bonus.h"
# include "map_bonus.h"

# include <stdbool.h>

# define ENTITY_UPDATE_PER_FRAME	1

# define DEMON_SPEED				2
# define DEMON_SQUARED_RADIUS		1
# define DEMON_HEALTH_POINT			3
# define DEMON_ATTACK_RANGE			1.5
# define DEMON_ATTACK_PAUSE			2
# define DEMON_ATTACK_DAMAGE		2

# define IMP_SPEED					2
# define IMP_SQUARED_RADIUS			0.5
# define IMP_HEALTH_POINT			2
# define IMP_ATTACK_RANGE			1.5
# define IMP_ATTACK_PAUSE			2
# define IMP_ATTACK_DAMAGE			1

typedef struct s_entity	t_entity;
typedef struct s_list	t_list;
typedef struct s_demon	t_demon;
typedef struct s_bullet	t_bullet;

struct s_entity
{
	float		speed;
	bool		is_path_circular;
	t_list		*path;
	t_sprite	*sprite;
	float		squared_radius;
	size_t		health_point;
	bool		(*update)(t_game *, t_entity *, float );
	bool		(*get_damage)(t_game *, t_entity *, size_t);
	bool		(*get_killed)(t_game *, t_entity *);
	bool		(*get_chainsawed)(t_game *, t_entity *);
	void		*type;
	float		cooldown;
	bool		see_player;
};

struct s_demon
{
	bool	stun;
	float	stun_start;
};

void	t_entity_destroy(void *data);
bool	init_entities(t_game *game);
bool	update_entities_path(t_game *game);
bool	move_entity(t_list *entities, t_vector *position, t_vector *move,
			t_map *map);
void	update_entities(t_game *game, float delta_time);
void	damage_entity(t_game *game, t_entity *entity, size_t damage);
void	update_entity_position(t_entity *entity, float delta_time,
			t_list *entities, t_map *map);
int		equal(void *a, void *b);
bool	entity_shoot_bullet(t_game *game, t_entity *entity,
			void (*use)(t_game *, t_bullet *));

// Init entities species
bool	demon_init(t_entity *entity, t_list *textures[MAP_NB_IDS]);
bool	demon_update(t_game *game, t_entity *entity, float delta_time);
bool	imp_init(t_entity *entity, t_list *textures[MAP_NB_IDS]);
bool	imp_update(t_game *game, t_entity *entity, float delta_time);
bool	init_entity_type(t_entity *entity, char id, \
			t_list *textures[MAP_NB_IDS]);

#endif // !ENTITIES_BONUS_H