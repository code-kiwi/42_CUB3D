/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_entities_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:43:13 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/18 03:34:48 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

static void	draw_map_get_entity_coords(
	t_vector *position,
	t_mlx_coords *coords,
	int tile_size,
	t_mlx_coords *map_draw_coords
)
{
	coords->x = (int) position->x * tile_size;
	coords->x += (position->x - (int)position->x) * (float)tile_size;
	coords->x += map_draw_coords->x;
	coords->y = (int) position->y * tile_size;
	coords->y += (position->y - (int)position->y) * (float)tile_size;
	coords->y += map_draw_coords->y;
}

static void	draw_map_player(t_map_draw *draw, t_player *player, t_image *img)
{
	t_mlx_coords	position;

	draw_map_get_entity_coords(&player->position, &position, draw->tile_size, \
		&draw->coords);
	t_mlx_draw_disk(img, &position, draw->element_radius, MAP_DRAW_COL_PLAYER);
}

void	draw_map_entities(t_map_draw *draw, t_game *game)
{
	draw_map_player(draw, &game->player, game->mlx.img_buff);
}
