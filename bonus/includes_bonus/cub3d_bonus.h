/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/20 09:57:43 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <stdbool.h>

# include "mlx_api_bonus.h"
# include "map_bonus.h"
# include "vector_bonus.h"
# include "player_bonus.h"
# include "ray_bonus.h"

# define PI						3.14159265358
# define FPS					100

# define WIN_TITLE				"Cub3D"
# define WIN_WIDTH				800
# define WIN_HEIGHT				800
# define MAX_DISTANCE			200

# define ERR_BASIC				"Error\n"
# define ERR_LITERALS			"Error\n%s\n"
# define ERR_ARG				"Bad argument given to the function"
# define ERR_PROG_ARGS			"Bad arguments, expected one argument"
# define ERR_GAME_INIT			"Impossible to intialize the t_game structure"
# define ERR_MLX_INIT			"Impossible to intialize the t_mlx structure"
# define ERR_GAME_LOOP			"Game loop failed"
# define ERR_HOOKS				"Impossible to add event handling"
# define ERR_RENDER				"Rendering error"
# define ERR_CAST_RAYS			"Ran in a wall"

# define ERR_WALLS				"Map not surrounded by walls"
# define ERR_ELEM				"Map elements not valid"
# define ERR_IDENTIFIER			"Map unknown identifier"
# define ERR_EMPTY_LINE			"Empty line in the map content"
# define ERR_MAP_EXTENSION		"Bad map extension, expected '.cub'"
# define ERR_MULTIPLE_PLAYERS	"Multiple players on the map"
# define ERR_MISSING_PLAYER		"Missing player"
# define ERR_MAP_EMPTY			"Missing map content"
# define ERR_PLAYER_QUIT_MAP	"Player out of bounds of the map"
# define ERR_MAP_OPEN			"Impossible to open the given map file"
# define ERR_MAP_CONTENT		"Reading failed, check the map content"
# define ERR_MISSING_TEXTURES	"Missing textures"
# define ERR_MAP_READ			"Map: read failed"

# define ERR_INIT_TEXTURES		"Can't open textures"
# define ERR_TEXTURE_EXTENSION	"Bad texture extension, expected '.xpm'"
# define ERR_MISSING_COMPONENT	"Missing element component"

typedef struct s_game	t_game;
typedef struct s_mlx	t_mlx;
typedef struct s_column	t_column;
typedef struct s_sprite	t_sprite;

struct	s_sprite
{
	t_vector	position;
	float		distance;
	t_image		*texture;
};

struct s_game
{
	t_mlx			mlx;
	t_player		player;
	t_map			map;
	t_vector		player_position;
	t_ray			rays[WIN_WIDTH];
	float			player_rotation_rad;
	long			frame_time_usec;
	long			tick_last_frame;
	t_image			textures[7];
	t_sprite		sprite;
};

struct	s_column
{
	size_t			texture_start;
	t_mlx_coords	coords;
	t_ray			*ray;
	float			perceived_height;
	int				start;
	int				end;
	int				texture_column;
	t_image 		*texture;
};

// Game functions
int			game_loop(t_game *game);
bool		t_game_init(t_game *game);
void		t_game_destroy(t_game *game);

// Render functions
void		draw_walls(t_game *game);
void		draw_ground_ceiling(t_column *column, int end, t_game *game,
				t_ray *ray);
void		draw_sprite(t_sprite *sprite, t_player *player, t_image *screen);
void		draw_texture_column(t_image *screen, t_column *column,
				t_image *texture);

// Utils functions
void		error_print(char *err_msg);
void		error_exit(t_game *game, char *err_msg);
size_t		array_length(void **array);
int			sign(float value);
ssize_t		find_str_in_array(char **array, char *str, size_t length);
void		free_array(char **array, size_t length, bool free_container);
void		print_str_array(char **array, size_t length);
int			min(int a, int b);
bool		is_number(char *str);
void		remove_last_breakline(char *str);
void		remove_last_spaces(char *str);
void		skip_next_spaces(char **str);
void		display_delta_time(void);
long		get_tick(void);

#endif
