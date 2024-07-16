/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:37:57 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/16 13:41:34 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

// #include <stdio.h>
// void	print_radar(t_radar *radar)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < radar->nb_tiles)
// 	{
// 		j = 0;
// 		while (j < radar->nb_tiles)
// 		{
// 			printf("%c", radar->tiles[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }

static void	draw_radar_tiles(
	t_image *img,
	t_mlx_coords *coords,
	t_mlx_coords *size,
	char tile_char
)
{
	if (tile_char == ID_MAP_SPACE)
		t_mlx_draw_rectangle_alphap(img, coords, size, COL_SPACE);
	else if (tile_char == ID_MAP_WALL)
		t_mlx_draw_rectangle_alphap(img, coords, size, COL_WALL);
	else if (tile_char == ID_MAP_DOOR_CLOSED)
		t_mlx_draw_rectangle_alphap(img, coords, size, COL_DOOR1);
	else if (tile_char == ID_MAP_DOOR_OPENED)
		t_mlx_draw_rectangle_alphap(img, coords, size, COL_DOOR2);
	else
		t_mlx_draw_rectangle_alphap(img, coords, size, COL_TILE);
}

static void	draw_radar_elements(
	t_image *img,
	t_mlx_coords *coords,
	int radius,
	char tile_char
)
{
	if (tile_char == ID_MAP_ENTITY)
		t_mlx_draw_disk_alphap(img, coords, radius, COL_ENTITY);
	else if (tile_char == ID_MAP_PLAYER)
		t_mlx_draw_disk_alphap(img, coords, radius, COL_PLAYER);
}

static void	draw_radar_process(t_radar *radar)
{
	int				i;
	int				j;
	t_mlx_coords	coords;
	t_mlx_coords	size;

	t_mlx_draw_disk(radar->img, &radar->center, radar->radius, RADAR_COLOR_BG);
	i = 0;
	while (i < radar->nb_tiles)
	{
		j = 0;
		while (j < radar->nb_tiles)
		{
			coords.x = radar->draw_offset + j * radar->tile_size;
			coords.y = radar->draw_offset + i * radar->tile_size;
			size.x = radar->tile_size;
			size.y = radar->tile_size;
			draw_radar_tiles(radar->img, &coords, &size, radar->tiles[i][j]);
			coords.x += radar->tile_size / 2;
			coords.y += radar->tile_size / 2;
			draw_radar_elements(radar->img, &coords, radar->radius_element, \
				radar->tiles[i][j]);
			j++;
		}
		i++;
	}
}

void	draw_radar(t_game *game, t_radar *radar, t_mlx *mlx)
{
	if (game == NULL || radar == NULL || mlx == NULL)
		return ;
	update_tiles(&game->map, radar, &game->player);
	if (radar->needs_update)
		draw_radar_process(radar);
	t_mlx_apply_image(radar->img, mlx->img_buff, &radar->coords);
}
