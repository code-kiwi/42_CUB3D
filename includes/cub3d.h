/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 09:25:55 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>

# include "map.h"
# include "vector.h"

# define PI 3.14159265358
# define ERROR_WALLS "Error\nMap not surrounded by walls\n"
# define ERROR_ELEM "Error\nMap elements not valid\n"
# define ERROR_IDENTIFIER "Error\nUnknown identifier\n"

typedef struct s_game	t_game;
typedef struct s_param	t_param;

struct s_param
{
	float	fov;
	size_t	width;
	size_t	height;
};

struct s_game
{
	t_map		map;
	t_param		param;
	t_vector	player_position;
	float		player_rotation_rad;
};

// Raycasting functions
float		raycast(t_vector position, t_vector *slope, t_map *map);
void		draw_walls(t_game *game);

// Utils functions
size_t		array_length(void **array);
int			sign(float value);
ssize_t		find_str_in_array(char **array, char *str, size_t length);
void		free_array(char **array, size_t length, bool free_container);
void		print_str_array(char **array, size_t length);

#endif
