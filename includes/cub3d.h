/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 10:42:43 by mhotting         ###   ########.fr       */
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

# define PI 3.14159265358

# define WIN_TITLE			"Cub3D"
# define WIN_WIDTH			800
# define WIN_HEIGHT			600

# define ERR_MSG_BASIC		"Cub3D - Error\n"
# define ERR_MSG_LITERALS	"Cub3D - Error: %s\n"
# define ERROR_MSG_ARG		"Bad argument given to the function"
# define ERR_MSG_GAME_INIT	"Impossible to intialize the t_game structure"
# define ERR_MSG_MLX_INIT	"Impossible to intialize the t_mlx structure"
# define ERR_MSG_GAME_LOOP	"Game loop failed"
# define ERR_MSG_HOOKS		"Impossible to add event handling"
# define ERR_MSG_RENDER		"Rendering error"

# define ERROR_WALLS "Error\nMap not surrounded by walls\n"
# define ERROR_ELEM "Error\nMap elements not valid\n"
# define ERROR_IDENTIFIER "Error\nUnknown identifier\n"

typedef struct s_game	t_game;
typedef struct s_mlx	t_mlx;
typedef struct s_param	t_param;

struct s_param
{
	float	fov;
	size_t	width;
	size_t	height;
};

struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_param		param;
	t_vector	player_position;
	float		player_rotation_rad;
};

// Game functions
int			game_loop(t_game *data);

// Raycasting functions
float		raycast(t_vector position, t_vector *slope, t_map *map);
void		draw_walls(t_game *game);

// t_game functions
bool		t_game_init(t_game *data);
void		t_game_destroy(t_game *data);

// Utils functions
void		error_print(char *err_msg);
void		error_exit(t_game *data, char *err_msg);
size_t		array_length(void **array);
int			sign(float value);
ssize_t		find_str_in_array(char **array, char *str, size_t length);
void		free_array(char **array, size_t length, bool free_container);
void		print_str_array(char **array, size_t length);

#endif
