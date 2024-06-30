/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:07:32 by brappo            #+#    #+#             */
/*   Updated: 2024/06/30 09:49:54 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_BONUS_H
# define ENTITIES_BONUS_H

# include "sprite_bonus.h"

# include <stdbool.h>

# define ENTITY_SPEED				2
# define ENTITY_RADIUS				0.5
# define ENTITY_UPDATE_PER_FRAME	1

typedef struct s_entity	t_entity;
typedef struct s_list	t_list;

struct s_entity
{
	float		speed;
	bool		is_path_circular;
	t_list		*path;
	t_sprite	*sprite;
	float		squared_radius;
};

void	t_entity_destroy(void *data);
bool	init_entities(t_game *game);
bool	update_entities_path(t_game *game);
void	move_entity(t_list *entities, t_vector *position, t_vector *move,
			t_map *map);

void	update_entities(t_list *entities, float delta_time, t_map *map);

#endif // !ENTITIES_BONUS_H