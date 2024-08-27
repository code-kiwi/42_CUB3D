/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 17:12:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <sys/types.h>
# include <stdbool.h>

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

# define WIN_TITLE				"Cub3D"
# define WIN_WIDTH				960
# define WIN_HEIGHT				500
# define MAX_DISTANCE			10
# define PAUSE_BG_DARK_FACTOR	0.4f

# define MAX_VISION_DISTANCE	10

# define ERR_BASIC				"Error\n"
# define ERR_LITERALS			"Error\n%s\n"
# define ERR_LITERALS_STR		"Error\n%s %s\n"
# define ERR_ARG				"Bad argument given to the function"
# define ERR_PROG_ARGS			"Bad arguments, expected one argument"
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
# define ERR_UI_CREATION		"UI creation failed"
# define ERR_RADAR_CREATION		"Radar creation failed"
# define ERR_MAP_DRAW_CREATION	"Map drawing cannot be created"
# define ERR_MAP_DRAW_SIZE		"Map drawing cannot be initialized: map too big"
# define ERR_WEAPONS_CREATION	"Weapons creation failed"
# define ERR_WEAPONS_RESIZE		"Weapon resizing failed"
# define ERR_P_WEAPONS_CREATION	"Player weapons creation failed"
# define ERR_ENTITY_CREATION	"Impossible to create the entity list"
# define ERR_NO_ENTITY			"The map does not contain any ennemy"
# define ERR_TOO_MUCH_ENTITIES	"The map contains too much entities"

# define ERR_INIT_TEXTURES		"Can't open texture"
# define ERR_TEXTURE_EXTENSION	"Bad texture extension, expected '.xpm'"
# define ERR_MISSING_COMPONENT	"Missing element component"
# define ERR_TEXTURE_SIZE		"Wrong texture size"

# define ERR_RECTANGLE			"You tried to draw an invalid rectangle"

# define ERR_BAD_ANIM_TIME		"The animation wait time is not a number"	
# define ERR_ANIM_TIME_TOO_BIG	"The animation wait time is too big"
# define ERR_ANIM_TIME_NEGATIVE	"The animation wait time is negative"

# define GAMEOVER_DARKNESS		0.999999f
# define GAMEOVER_DARKNESS_LOOP	1000
# define GAMEWON_BRIGHTNESS		1.025f
# define GAMEWON_BRIGHT_LOOP	1000

# define NB_MAX_ENTITIES		100

typedef struct s_game			t_game;
typedef struct s_mlx			t_mlx;
typedef struct s_column			t_column;
typedef struct s_sprite			t_sprite;
typedef struct s_door			t_door;
typedef struct s_list			t_list;

struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_map		map;
	t_ray		rays[WIN_WIDTH];
	long		frame_time_usec;
	long		tick_last_frame;
	t_animation	anim[MAP_NB_IDS];
	size_t		door_count;
	t_door		*doors;
	t_door		*last_door_seen;
	t_list		*sprites;
	t_list		*entities;
	t_list		*bullets;
	t_list		*last_entity_updated;
	t_weapon	weapons[NB_TOT_WEAPONS];
	bool		pause;
	t_ui		ui_pause;
	t_ui		ui_game_over;
	t_ui		ui_win;
	bool		mouse_hidden;
	t_radar		radar;
	bool		map_opened;
	t_hud		hud;
	bool		game_over;
	int			game_end_loop_count;
	bool		game_won;
};

struct	s_column
{
	size_t			texture_start;
	t_mlx_coords	coords;
	float			perceived_height;
	int				start;
	int				end;
	int				real_ground_start;
	int				real_ceiling_start;
	int				texture_column;
};

// Game functions
int		game_loop(t_game *game);
bool	t_game_init(t_game *game);
void	t_game_destroy(t_game *game);
void	t_game_destroy_and_exit(t_game *game);
void	game_pause_switch(t_game *game);
void	game_pause_close(t_game *game);

// Render functions
void	draw_walls(t_game *game);
void	draw_texture_column(t_image *screen, t_column *column,
			t_image *texture, float distance);
void	render_all_sprites(t_game *game);
void	get_sprite_screen_pos(t_mlx_coords *sprite_screen, t_sprite *sprite,
			t_game *game, float scale);
bool	is_sprite_aimed(t_sprite *sprite, int left_x);
void	draw_ground(t_column *column, int start, t_game *game, t_ray *ray);
void	draw_ceiling(t_column *column, int start, t_game *game, t_ray *ray);

// Utils functions
void	error_print(char *err_msg);
void	error_print_string(char *err_msg, char *str);
void	error_exit(t_game *game, char *err_msg);
size_t	array_length(void **array);
int		sign(float value);
ssize_t	find_str_in_array(char **array, char *str, size_t length);
void	free_array(char **array, size_t length, bool free_container);
char	**create_str_array(size_t nb_row, size_t nb_col, char default_value);
int		min(int a, int b);
int		max_int(int a, int b);
bool	is_number(char *str);
void	remove_last_breakline(char *str);
void	remove_last_spaces(char *str);
void	skip_next_spaces(char **str);
long	get_tick(void);
void	sort_list(t_list *lst, float compare(void *, void *));

#endif
