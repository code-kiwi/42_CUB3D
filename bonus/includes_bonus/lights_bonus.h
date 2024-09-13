/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 04:14:23 by brappo            #+#    #+#             */
/*   Updated: 2024/09/13 03:52:00 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_BONUS_H
# define LIGHTS_BONUS_H

# define LIGHT_SQUARED_DISTANCE	25
# define LIGHT_DISTANCE			5
# define DEFAULT_LUMINOSITY		0.2f
# define SKY_LUMINOSITY			0.5f
# define LIGHT_RAY_BY_ANGLE		1

# include "vector_bonus.h"

# include <stddef.h>
# include <stdbool.h>

typedef struct s_map	t_map;
typedef struct s_game	t_game;
typedef struct s_light	t_light;

struct	s_light
{
	t_vector	position;
	float		*rays;
};

bool	get_lights_position(t_map *map);
size_t	count_lights(t_map *map);
bool	init_lights(t_game *game);
float	get_luminosity(t_vector *position, t_map *map, float distance);
bool	set_lights_values(t_game *game);
void	free_lights(t_light **lights, size_t lights_count);

#endif // !LIGHTS_BONUS_H