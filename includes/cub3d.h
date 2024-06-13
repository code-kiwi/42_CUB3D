/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 09:39:40 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdbool.h>

# define PI 3.14159265358

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_map
{
	char	**tiles;
	size_t	*lines_lengths;
	size_t	lines_count;
}	t_map;

typedef struct s_param
{
	float	fov;
	size_t	width;
	size_t	height;
}	t_param;

typedef struct s_game
{
	t_map		map;
	t_param		param;
	t_vector	player_position;
	float		player_rotation_rad;
	char		textures[4];
}	t_game;

bool		is_in_bounds(t_vector *position, t_map *map);
void		copy(t_vector *dest, t_vector *src);
t_vector	vector_error(void);
int			sign(float value);
void		vector_print(char *prefix, t_vector *vector);
void		vector_init(t_vector *vector, float x, float y);
void		get_slope(t_vector *slope, float angle_rad);
float		raycast(t_vector position, t_vector *slope, t_map *map);
size_t		array_length(void **array);
size_t		print_str_array(char **array);
bool		read_map(t_map *map, char *filename);
void		free_array(char **array);
void		draw_walls(t_game *game);

#endif
