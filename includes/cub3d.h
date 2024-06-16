/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/16 15:39:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <sys/types.h>
# include <stdbool.h>

# include "mlx_api.h"
# include "map.h"
# include "vector.h"
# include "player.h"
# include "ray.h"

# define PI 3.14159265358

# define WIN_TITLE				"Cub3D"
# define WIN_WIDTH				1900
# define WIN_HEIGHT				1000

# define ERR_BASIC				"Error\n"
# define ERR_LITERALS			"Error\n%s\n"
# define ERR_ARG				"Bad argument given to the function"
# define ERR_GAME_INIT			"Impossible to intialize the t_game structure"
# define ERR_MLX_INIT			"Impossible to intialize the t_mlx structure"
# define ERR_GAME_LOOP			"Game loop failed"
# define ERR_HOOKS				"Impossible to add event handling"
# define ERR_RENDER				"Rendering error"
# define ERR_MAP_READ			"Map reading"
# define ERR_WALLS				"Map not surrounded by walls"
# define ERR_ELEM				"Map elements not valid"
# define ERR_IDENTIFIER			"Map unknown identifier"
# define ERR_PLAYER_INIT		"Player init failed"
# define ERR_INIT_TEXTURES		"Can't open textures"
# define ERR_MISSING_TEXTURES	"Missing textures"

typedef struct s_game	t_game;
typedef struct s_mlx	t_mlx;
typedef struct s_column	t_column;

struct s_game
{
	t_mlx		mlx;
	t_player	player;
	t_map		map;
	t_vector	player_position;
	t_ray		rays[WIN_WIDTH];
	float		player_rotation_rad;
	t_image		textures[4];
};

struct	s_column
{
	size_t			texture_start;
	size_t			column;
	t_mlx_coords	coords;
	t_ray			*ray;
	float			perceived_height;
};

// Game functions
int			game_loop(t_game *game);
bool		t_game_init(t_game *game);
void		t_game_destroy(t_game *game);

// Render functions
bool		draw_walls(t_image *screen, t_ray *rays, t_image textures[4]);
bool		draw_color_column(t_image *screen, t_mlx_coords *coords,
				unsigned int color, int end);
bool		draw_texture_column(t_image *screen, t_column *column, int wall_end,
	t_image textures[4]);

// Utils functions
void		error_print(char *err_msg);
void		error_exit(t_game *game, char *err_msg);
size_t		array_length(void **array);
int			sign(float value);
ssize_t		find_str_in_array(char **array, char *str, size_t length);
void		free_array(char **array, size_t length, bool free_container);
void		print_str_array(char **array, size_t length);
int			min(int a, int b);

#endif
