/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:43:13 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/18 04:21:05 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

static void	draw_map_decoration(t_map_draw *draw, t_image *img)
{
	int				i;
	t_mlx_coords	line_start;
	t_mlx_coords	line_end;
	int				lim;

	i = -1;
	lim = draw->size.y / draw->tile_size;
	while (++i <= lim)
	{
		line_start.x = draw->coords.x;
		line_start.y = draw->coords.y + i * draw->tile_size;
		line_end.x = draw->coords.x + draw->size.x;
		line_end.y = draw->coords.y + i * draw->tile_size;
		t_mlx_draw_line(img, line_start, line_end, MAP_DRAW_COL_DECORATION);
	}
	i = -1;
	lim = draw->size.x / draw->tile_size;
	while (++i <= lim)
	{
		line_start.x = draw->coords.x + i * draw->tile_size;
		line_start.y = draw->coords.y;
		line_end.x = draw->coords.x + i * draw->tile_size;
		line_end.y = draw->coords.y + draw->size.y;
		t_mlx_draw_line(img, line_start, line_end, MAP_DRAW_COL_DECORATION);
	}
}

static uint32_t	get_tile_color(char c)
{
	if (c == ID_MAP_SPACE)
		return (MAP_DRAW_COL_SPACE);
	else if (c == ID_MAP_WALL)
		return (MAP_DRAW_COL_WALL);
	else if (c == ID_MAP_DOOR_CLOSED)
		return (MAP_DRAW_COL_DOOR1);
	else if (c == ID_MAP_DOOR_OPENED)
		return (MAP_DRAW_COL_DOOR2);
	else
		return (MAP_DRAW_COL_TILE);
}

static void	draw_map_tiles(t_map_draw *draw, t_map *map, t_image *img)
{
	int				i;
	size_t			j;
	t_mlx_coords	coords;
	t_mlx_coords	size;

	(void) map;
	size.x = draw->tile_size;
	size.y = draw->tile_size;
	i = 0;
	while (i < draw->nb_tiles.y)
	{
		coords.y = draw->coords.y + i * draw->tile_size;
		j = 0;
		while (j < map->lines_lengths[i])
		{
			coords.x = draw->coords.x + j * draw->tile_size;
			t_mlx_draw_rectangle(img, &coords, &size, \
				get_tile_color(map->tiles[i][j]));
			j++;
		}
		i++;
	}
}

void	draw_map(t_map_draw *draw, t_map *map, t_game *game)
{
	if (draw == NULL || map == NULL || game == NULL)
		return ;
	t_mlx_draw_rectangle(game->mlx.img_buff, &draw->coords, &draw->size, \
		MAP_DRAW_COL_BG);
	draw_map_tiles(draw, map, game->mlx.img_buff);
	draw_map_entities(draw, game);
	draw_map_decoration(draw, game->mlx.img_buff);
}
