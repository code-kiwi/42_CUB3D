/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:07:32 by brappo            #+#    #+#             */
/*   Updated: 2024/07/11 11:20:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_BONUS_H
# define ENTITIES_BONUS_H

# include "sprite_bonus.h"

# include <stdbool.h>

# define ENTITY_SPEED				2
# define ENTITY_RADIUS				0.5
# define ENTITY_UPDATE_PER_FRAME	1
# define ENTITY_HEALTH_POINT		3

typedef struct s_entity	t_entity;
typedef struct s_list	t_list;

struct s_entity
{
	float		speed;
	bool		is_path_circular;
	t_list		*path;
	t_sprite	*sprite;
	float		squared_radius;
	size_t		health_point;
};

void	t_entity_destroy(void *data);
bool	init_entities(t_game *game);
bool	update_entities_path(t_game *game);
void	move_entity(t_list *entities, t_vector *position, t_vector *move,
			t_map *map);
void	update_entities(t_list *entities, float delta_time, t_map *map);
void	damage_entity(t_game *game, t_entity *entity, size_t damage);

#endif // !ENTITIES_BONUS_H