/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:07:32 by brappo            #+#    #+#             */
/*   Updated: 2024/06/29 14:15:29 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_BONUS_H
# define ENTITIES_BONUS_H

# include "sprite_bonus.h"

# include <stdbool.h>

# define ENTITY_SPEED	2

typedef struct s_entity	t_entity;
typedef struct s_list	t_list;

struct s_entity
{
	float		speed;
	bool		is_path_circular;
	t_list		*path;
	t_sprite	sprite;
};

void	update_entities(t_list *entities, float delta_time);

#endif // !ENTITIES_BONUS_H