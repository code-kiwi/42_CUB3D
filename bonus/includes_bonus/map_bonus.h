/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 23:55:44 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/19 10:50:00 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <stdlib.h>

# include "mlx_api_bonus.h"

# define ID_MAP_WALL					'1'
# define ID_MAP_TILE					'0'
# define ID_MAP_SPACE					' '
# define ID_MAP_DOOR_CLOSED				'd'
# define ID_MAP_DOOR_OPENED				'o'
# define ID_MAP_SPRITE					's'
# define ID_MAP_ENTITY					'e'
# define ID_MAP_PLAYER					'P'

# define ID_TEXTURE_NORTH				"NO"
# define ID_TEXTURE_SOUTH				"SO"
# define ID_TEXTURE_WEST				"WE"
# define ID_TEXTURE_EAST				"EA"
# define ID_TEXTURE_FLOOR				"F"
# define ID_TEXTURE_CEILING				"C"
# define ID_TEXTURE_DOOR				"D"
# define ID_TEXTURE_ENTITY				"E"
# define ID_TEXTURE_UI_PAUSE_BG			"UI_PAUSE_BG"
# define ID_TEXTURE_UI_PAUSE_LABEL		"UI_PAUSE_LABEL"
# define ID_TEXTURE_UI_PAUSE_BTNR_OFF	"UI_PAUSE_BTN_RESUME_OFF"
# define ID_TEXTURE_UI_PAUSE_BTNR_ON	"UI_PAUSE_BTN_RESUME_ON"
# define ID_TEXTURE_UI_PAUSE_BTNQ_OFF	"UI_PAUSE_BTN_QUIT_OFF"
# define ID_TEXTURE_UI_PAUSE_BTNQ_ON	"UI_PAUSE_BTN_QUIT_ON"

# define IDX_TXTR_N						0
# define IDX_TXTR_S						1
# define IDX_TXTR_W						2
# define IDX_TXTR_E						3
# define IDX_TXTR_FLOOR					4
# define IDX_TXTR_CEIL					5
# define IDX_TXTR_DOOR					6
# define IDX_TXTR_ENTITITES				7
# define IDX_TXTR_UIP_BG				8
# define IDX_TXTR_UIP_LBL				9
# define IDX_TXTR_UIP_B1_ON				10
# define IDX_TXTR_UIP_B1_OFF			11
# define IDX_TXTR_UIP_B2_ON				12
# define IDX_TXTR_UIP_B2_OFF			13

# define MAP_EXTENSION					".cub"
# define MAP_ALLOWED_CHARS				" 01sdeNSEW"
# define MAP_NB_IDS						14

# define MAP_MOVING_CHARS				"PNSEWe"

# define MAP_BG_DARK_FACTOR				0.6f
# define MAP_DRAW_SIZE_RATIO			0.80f
# define MAP_DRAW_ELT_MIN_RADIUS		8
# define MAP_DRAW_MIN_TILE_SIZE			2
# define MAP_DRAW_COL_BG				0x002801
# define MAP_DRAW_COL_DECORATION		0x007000
# define MAP_DRAW_COL_SPACE				0x002801
# define MAP_DRAW_COL_WALL				0x09BB17
# define MAP_DRAW_COL_TILE				0x006700
# define MAP_DRAW_COL_DOOR1				0x00FF00
# define MAP_DRAW_COL_DOOR2				0x006700
# define MAP_DRAW_COL_PLAYER			0xFFFF00
# define MAP_DRAW_COL_RAYS				0x008700
# define MAP_DRAW_COL_ENNEMIES			0xFF0000

typedef struct s_game		t_game;
typedef struct s_map		t_map;
typedef struct s_map_draw	t_map_draw;
typedef struct s_vector		t_vector;
typedef struct s_door		t_door;
typedef struct s_ray		t_ray;
typedef struct s_sprite		t_sprite;
typedef struct s_list		t_list;
typedef struct s_mlx_coords	t_mlx_coords;

struct s_map_draw
{
	int				tile_size;
	t_mlx_coords	coords;
	t_mlx_coords	size;
	t_mlx_coords	nb_tiles;
	int				element_radius;
};

struct s_map
{
	char			**tiles;
	size_t			*lines_lengths;
	size_t			lines_count;
	char			*textures[MAP_NB_IDS];
	t_mlx_coords	texture_size[MAP_NB_IDS];
	t_map_draw		draw;
};

// Map functions
bool	read_map(t_map *map, char *filename);
bool	is_map_valid(t_map *map);
bool	read_elements(t_map *map, int fd);
bool	is_in_bounds(t_vector *position, t_map *map);
bool	is_character(t_vector *position, t_map *map, char character);
bool	check_extension(char *filename, char *extension);
void	free_map(t_map *map);
bool	is_walkable(t_map *map, t_mlx_coords *coords);
bool	get_elem_into_list(t_map *map, t_list **dest, char id, \
			bool add_elem(t_list **, float, float));
void	update_map(t_map *map, t_game *game);

// Draw map functions
void	draw_map(t_map_draw *map_draw, t_map *map, t_game *game);
void	draw_map_entities(t_map_draw *draw, t_game *game);
bool	init_map_draw(t_map_draw *map_draw, t_map *map, t_game *game);

#endif
