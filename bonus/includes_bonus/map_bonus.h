/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:55:44 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/29 14:53:23 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <stdlib.h>

# define ID_MAP_WALL		'1'
# define ID_MAP_TILE		'0'
# define ID_MAP_SPACE		' '
# define ID_MAP_DOOR_CLOSED	'd'
# define ID_MAP_DOOR_OPENED	'o'
# define ID_MAP_SPRITE		's'
# define ID_MAP_ENTITY		'e'

# define ID_TEXTURE_NORTH	"NO"
# define ID_TEXTURE_SOUTH	"SO"
# define ID_TEXTURE_WEST	"WE"
# define ID_TEXTURE_EAST	"EA"
# define ID_TEXTURE_FLOOR	"F"
# define ID_TEXTURE_CEILING	"C"
# define ID_TEXTURE_DOOR	"D"
# define ID_TEXTURE_SPRITE	"S"
# define ID_TEXTURE_ENTITY	"E"

# define MAP_EXTENSION		".cub"
# define MAP_ALLOWED_CHARS	" 01sdeNSEW"
# define MAP_NB_IDS			8

typedef struct s_game		t_game;
typedef struct s_map		t_map;
typedef struct s_vector		t_vector;
typedef struct s_door		t_door;
typedef struct s_ray		t_ray;
typedef struct s_sprite		t_sprite;
typedef struct s_list		t_list;
typedef struct s_mlx_coords	t_mlx_coords;

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
bool		is_walkable(t_map *map, t_mlx_coords *coords);
bool		get_elem_into_list(t_map *map, t_list **dest, char id, \
				bool add_elem(t_list **, float, float));

#endif
