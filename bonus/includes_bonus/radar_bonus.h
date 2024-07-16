/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:52:04 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/16 14:50:00 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADAR_BONUS_H
# define RADAR_BONUS_H

# include <stdbool.h>
# include <stdint.h>

# define RADAR_SIZE_RATIO		10.0f
# define RADAR_OFFSET			10
# define RADAR_COLOR_BG			0x002801
# define RADAR_NB_TILES			17

# define COL_SPACE				0x002801
# define COL_WALL				0x09BB17
# define COL_TILE				0x006700
# define COL_DOOR1				0x00FF00
# define COL_DOOR2				0x006700
# define COL_PLAYER				0xFFFF55
# define COL_ENTITY				0xFF2222

typedef struct s_game	t_game;
typedef struct s_radar	t_radar;

struct s_radar
{
	t_mlx_coords	coords;
	t_mlx_coords	center;
	int				draw_offset;
	int				radius;
	t_image			*img;
	float			player_last_orientation;
	uint32_t		color_border;
	char			**tiles;
	int				nb_tiles;
	bool			needs_update;
	int				tile_size;
	int				radius_element;
};

// Radar functions
bool	init_radar(t_radar *radar, t_mlx *mlx);
void	destroy_radar(t_radar *radar, void *mlx_ptr);
void	draw_radar(t_game *game, t_radar *radar, t_mlx *mlx);
void	update_tiles(t_map *map, t_radar *radar, t_player *player);

#endif
