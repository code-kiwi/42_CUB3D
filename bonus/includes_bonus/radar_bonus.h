/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:52:04 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/15 13:48:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADAR_BONUS_H
# define RADAR_BONUS_H

# include <stdbool.h>
# include <stdint.h>

# define RADAR_SIZE_RATIO	12.5f
# define RADAR_OFFSET		10
# define RADAR_COLOR_BG		0xFFFFFF
# define RADAR_TILES_SIZE	10

typedef struct s_game	t_game;
typedef struct s_radar	t_radar;

struct s_radar
{
	t_mlx_coords	coords;
	t_mlx_coords	center;
	int				radius;
	t_image			*img;
	t_vector		player_last_position;
	float			player_last_orientation;
	uint32_t		color_bg;
	uint32_t		color_border;
	char			**tiles;
	size_t			tiles_size;
	bool			needs_update;
};

// Radar functions
bool	init_radar(t_radar *radar, t_mlx *mlx);
void	destroy_radar(t_radar *radar, void *mlx_ptr);
void	draw_radar(t_game *game, t_radar *radar, t_mlx *mlx);

#endif
