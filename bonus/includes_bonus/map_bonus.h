/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:55:44 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/22 17:20:55 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <stdlib.h>

# define ID_WALL			'1'
# define ID_TILE			'0'
# define ID_SPACE			' '
# define ID_DOOR_CLOSED		'd'
# define ID_DOOR_OPENED		'o'

# define ID_NORTH			"NO"
# define ID_SOUTH			"SO"
# define ID_WEST			"WE"
# define ID_EAST			"EA"
# define ID_FLOOR			"F"
# define ID_CEILING			"C"
# define ID_DOOR			"D"

# define MAP_EXTENSION		".cub"
# define MAP_ALLOWED_CHARS	" 01dNSEW"
# define MAP_NB_IDS			7

typedef struct s_game	t_game;
typedef struct s_map	t_map;
typedef struct s_vector	t_vector;
typedef struct s_door	t_door;
typedef struct s_ray	t_ray;

struct s_map
{
	char	**tiles;
	size_t	*lines_lengths;
	size_t	lines_count;
	char	*textures[MAP_NB_IDS];
};

// Map functions
bool		read_map(t_map *map, char *filename);
bool		is_map_valid(t_map *map);
bool		read_elements(t_map *map, int fd);
bool		is_in_bounds(t_vector *position, t_map *map);
bool		is_character(t_vector *position, t_map *map, char character);
bool		check_extension(char *filename, char *extension);
void		free_map(t_map *map);
size_t		count_doors(t_map *map);
void		find_doors(t_map *map, size_t door_count, t_door *doors);
t_door		*find_door_at_position(t_mlx_coords *position, t_door *doors,
				size_t doors_count);
void		open_looked_door(t_ray *look_ray, t_map *map);
void		update_door(t_door *door, float delta_time, t_map *map,
				t_vector *player_pos);

#endif
