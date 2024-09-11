/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/11 10:47:46 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <sys/types.h>
# include <stdbool.h>
# include <pthread.h>

# include "mlx_api_bonus.h"
# include "map_bonus.h"
# include "vector_bonus.h"
# include "player_bonus.h"
# include "ray_bonus.h"
# include "ui_bonus.h"
# include "animation_bonus.h"
# include "radar_bonus.h"
# include "weapons_bonus.h"
# include "hud_bonus.h"

# define PI						3.14159265358
# define FPS					100
# define NB_DRAW_THREADS		16

# define WIN_TITLE				"Cub3D"
# define WIN_WIDTH				1920
# define WIN_HEIGHT				1000
# define MAX_DISTANCE			10
# define PAUSE_BG_DARK_FACTOR	0.4f

# define MAX_VISION_DISTANCE	10

# define ERR_BASIC				"Error\n"
# define ERR_LITERALS			"Error\n%s\n"
# define ERR_LITERALS_STR		"Error\n%s %s\n"
# define ERR_LITERALS_CHAR		"Error\n%s '%c'\n"

# define ERR_ARG				"Bad argument given to the function"
# define ERR_PROG_ARGS			"Bad arguments, no argument expected"
# define ERR_GAME_INIT			"Impossible to intialize the t_game structure"
# define ERR_MLX_INIT			"Impossible to intialize the t_mlx structure"
# define ERR_GAME_LOOP			"Game loop failed"
# define ERR_HOOKS				"Impossible to add event handling"
# define ERR_RENDER				"Rendering error"
# define ERR_CAST_RAYS			"Ran in a wall"

# define ERR_FPS				"Error calculating fps"
# define INVALID_DOOR			"Door should be between two walls."
# define ERR_WALLS				"Map not surrounded by walls"
# define ERR_ELEM				"Map elements not valid"
# define ERR_IDENTIFIER			"Map unknown identifier"
# define ERR_EMPTY_LINE			"Empty line in the map content"
# define ERR_MAP_EXTENSION		"Bad map extension, expected '.cub'"
# define ERR_MULTIPLE_PLAYERS	"Multiple players on the map"
# define ERR_MISSING_PLAYER		"Missing player"
# define ERR_PLAYER_CREATION	"Impossible to create the player"
# define ERR_MAP_EMPTY			"Missing map content"
# define ERR_PLAYER_QUIT_MAP	"Player out of bounds of the map"
# define ERR_MAP_OPEN			"Impossible to open the given map file"
# define ERR_MAP_CONTENT		"Reading failed, check the map content"
# define ERR_MISSING_TEXTURES	"Missing texture"
# define ERR_MAP_READ			"Map: read failed"
# define ERR_BAD_SIZE			"Wrong or missing texture size"
# define ERR_SIZE_TOO_BIG		"Size too big, max 4 characters"
# define ERR_NEGATIVE_SIZE		"Invalid negative size"
# define ERR_RADAR_CREATION		"Radar creation failed"
# define ERR_MAP_DRAW_CREATION	"Map drawing cannot be created"
# define ERR_MAP_DRAW_SIZE		"Map drawing cannot be initialized: map too big"
# define ERR_WEAPONS_CREATION	"Weapons creation failed"
# define ERR_WEAPONS_RESIZE		"Weapon resizing failed"
# define ERR_P_WEAPONS_CREATION	"Player weapons creation failed"
# define ERR_ENTITY_CREATION	"Impossible to create the entity list"
# define ERR_TOO_MUCH_ENTITIES	"The map contains too much entities"

# define ERR_UIS_CREATION		"UIs could not be created"
# define ERR_UIS_IDS_CREATION	"UIs identifiers could not be set"
# define ERR_UIS_TXTR_PATH		"The UIs texture file couuld not be opened"
# define ERR_UIS_READ			"Impossible to read the texture file for UIs"
# define ERR_UIS_READ_ELEMENT	"Impossible to read one of the UIs textures"
# define ERR_UIS_IDENTIFIER		"Invalid or duplicated identifier for UIs"
# define ERR_UIS_IMG_INIT		"Impossible to init image from file"
# define ERR_UI_CREATION		"UI creation failed"

# define ERR_INIT_TEXTURES		"Can't open texture"
# define ERR_TEXTURE_EXTENSION	"Bad texture extension, expected '.xpm'"
# define ERR_MISSING_COMPONENT	"Missing element component"
# define ERR_TEXTURE_SIZE		"Wrong texture size"
# define ERR_MAP_LOAD			"Impossible to load the map"
# define ERR_MAP_UNLOAD			"Impossible to unload the map"

# define ERR_RECTANGLE			"You tried to draw an invalid rectangle"

# define ERR_BAD_ANIM_TIME		"The animation wait time is not a number"	
# define ERR_ANIM_TIME_TOO_BIG	"The animation wait time is too big"
# define ERR_ANIM_TIME_NEGATIVE	"The animation wait time is negative"

# define ERR_DRAW_WALL			"The wall drawing failed"
# define ERR_UPDATE_ENTITIES	"The entity updating process failed"
# define ERR_UPDATE_ANIMATIONS	"The animation updatig process failed"

# define GAMEOVER_DARKNESS		0.999999f
# define GAMEOVER_DARKNESS_LOOP	1000
# define GAMEWON_BRIGHTNESS		1.025f
# define GAMEWON_BRIGHT_LOOP	1000

# define NB_MAX_ENTITIES		100
# define NO_MAP_LOADED_INDEX	-1

typedef struct s_game				t_game;
typedef struct s_draw_thread_arg	t_draw_thread_arg;
typedef struct s_mlx				t_mlx;
typedef struct s_column				t_column;
typedef struct s_sprite				t_sprite;
typedef struct s_door				t_door;
typedef struct s_list				t_list;
typedef enum e_game_state			t_game_state;

struct s_draw_thread_arg
{
	t_game	*game;
	size_t	start;
	size_t	end;
};

enum e_game_state
{
	STATE_GAMEOVER,
	STATE_GAMEWIN,
	STATE_HOME,
	STATE_LEVEL_SELECTION,
	STATE_PLAYING,
	STATE_PAUSE,
};

struct s_game
{
	t_game_state		state;
	t_mlx				mlx;
	t_player			player;
	ssize_t				curr_map_index;
	t_map				*map;
	t_map				maps[NB_MAPS];
	t_ray				rays[WIN_WIDTH];
	long				frame_time_usec;
	long				tick_last_frame;
	t_animation			*anim;
	t_animation			anims[NB_MAPS][MAP_NB_IDS];
	t_door				*last_door_seen;
	t_list				*sprites;
	t_list				*entities;
	t_list				*bullets;
	t_list				*last_entity_updated;
	t_weapon			weapons[NB_TOT_WEAPONS];
	t_game_uis			uis;
	bool				mouse_hidden;
	t_radar				radar;
	bool				map_opened;
	t_hud				hud;
	int					game_end_loop_count;
	pthread_t			threads[NB_DRAW_THREADS];
	t_draw_thread_arg	draw_thread_args[NB_DRAW_THREADS];
};

struct	s_column
{
	size_t			texture_start;
	int				texture_x;
	t_mlx_coords	coords;
	float			perceived_height;
	int				start;
	int				end;
	int				ground_start;
	int				ceiling_start;
	int				ranged_end;
	int				ranged_start;
	float			luminosity;
};

// Game functions
int		game_loop(t_game *game);
bool	t_game_init(t_game *game);
void	t_game_destroy(t_game *game);
void	t_game_destroy_and_exit(t_game *game);
void	game_pause_switch(t_game *game);
void	game_pause_close(t_game *game);
void	game_reach_level_selection(t_game *game);
void	game_reach_home(t_game *game);

// Render functions
bool	draw_walls(t_game *game);
void	draw_walls_part(t_game *game, size_t start, size_t end);
void	draw_texture_column(t_image *screen, t_column *column,
			t_image *texture);
void	render_all_sprites(t_game *game);
void	get_sprite_screen_pos(t_column *column, t_sprite *sprite, \
			t_game *game, float scale);
bool	is_sprite_aimed(t_sprite *sprite, int left_x);
void	draw_ground(t_column *column, int start, t_game *game, t_ray *ray);
void	draw_ceiling(t_column *column, int start, t_game *game, t_ray *ray);
int		get_offset(float perceived_height, t_player *player);
void	draw_sky(t_game *game);
bool	is_sky(t_vector *pixel_pos, t_map *map);

// Map selection
void	select_level1(t_game *game);
void	select_level2(t_game *game);
void	select_level3(t_game *game);
void	select_level4(t_game *game);
void	select_level5(t_game *game);
void	quit_level(t_game *game);
bool	game_load_map(t_game *game, size_t map_index);
void	game_unload_map(t_game *game);
void	reload_level(t_game *game);

// Utils functions
void	error_print(char *err_msg);
void	error_print_string(char *err_msg, char *str);
void	error_print_char(char *err_msg, char c);
void	error_exit(t_game *game, char *err_msg);
size_t	array_length(void **array);
int		sign(float value);
ssize_t	find_str_in_array(char **array, char *str, size_t length);
void	free_array(char **array, size_t length, bool free_container);
char	**create_str_array(size_t nb_row, size_t nb_col, char default_value);
int		min(int a, int b);
int		max_int(int a, int b);
bool	get_random_bool(float probability);
bool	is_number(char *str);
void	remove_last_breakline(char *str);
void	remove_last_spaces(char *str);
void	skip_next_spaces(char **str);
long	get_tick(void);
void	sort_list(t_list *lst, float compare(void *, void *));
float	range(float value, float min, float max);

#endif
