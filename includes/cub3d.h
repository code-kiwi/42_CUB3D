/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:41:27 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 17:56:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx_api.h"

# define WIN_TITLE			"Cub3D"
# define WIN_WIDTH			800
# define WIN_HEIGHT			600

# define ERR_MSG_BASIC		"Cub3D - Error\n"
# define ERR_MSG_LITERALS	"Cub3D - Error: %s\n"
# define ERROR_MSG_ARG		"Bad argument given to the function"
# define ERR_MSG_DATA_INIT	"Impossible to intialize the t_cub_data structure"
# define ERR_MSG_MLX_INIT	"Impossible to intialize the t_mlx structure"
# define ERR_MSG_GAME_LOOP	"Game loop failed"
# define ERR_MSG_HOOKS		"Impossible to add event handling"

typedef struct s_cub_data	t_cub_data;
typedef struct s_mlx		t_mlx;

struct s_cub_data
{
	t_mlx	mlx;
};

// Game functions
int		game_loop(t_cub_data *data);

// t_cub_data functions
bool	t_cub_data_init(t_cub_data *data);
void	t_cub_data_destroy(t_cub_data *data);

// Utils functions
void	error_print(char *err_msg);
void	error_exit(t_cub_data *data, char *err_msg);

#endif
