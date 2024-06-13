/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 00:09:12 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>

# include "map.h"

# define PI 3.14159265358
# define ERROR_WALLS "Error\nMap not surrounded by walls\n"
# define ERROR_ELEM "Error\nMap elements not valid\n"
# define ERROR_IDENTIFIER "Error\nUnknown identifier\n"

typedef struct s_vector	t_vector;
typedef struct s_param	t_param;
typedef struct s_game	t_game;

struct s_vector
{
	float	x;
	float	y;
};

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

bool		is_in_bounds(t_vector *position, t_map *map);
void		copy(t_vector *dest, t_vector *src);
t_vector	vector_error(void);
int			sign(float value);
void		vector_print(char *prefix, t_vector *vector);
void		vector_init(t_vector *vector, float x, float y);
void		get_slope(t_vector *slope, float angle_rad);
float		raycast(t_vector position, t_vector *slope, t_map *map);
size_t		array_length(void **array);
void		print_str_array(char **array, size_t length);
void		free_array(char **array, size_t length, bool free_container);
void		draw_walls(t_game *game);
ssize_t		find_str_in_array(char **array, char *str, size_t length);

#endif
