/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_entities_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:43:13 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/19 10:37:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "entities_bonus.h"

static void	get_coords(
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

	get_coords(&player->position, &position, draw->tile_size, &draw->coords);
	t_mlx_draw_disk(img, &position, draw->element_radius, MAP_DRAW_COL_PLAYER);
}

static void	draw_map_rays(
	t_map_draw *draw,
	t_player *player,
	t_ray *rays,
	t_image *img
)
{
	t_mlx_coords	save;
	t_mlx_coords	pos;
	t_mlx_coords	ray_end;
	size_t			i;

	get_coords(&player->position, &save, draw->tile_size, &draw->coords);
	i = 0;
	while (i < WIN_WIDTH)
	{
		pos.x = save.x;
		pos.y = save.y;
		get_coords(&rays[i].intersection, &ray_end, draw->tile_size, \
			&draw->coords);
		t_mlx_draw_line(img, pos, ray_end, MAP_DRAW_COL_RAYS);
		i++;
	}
}

static void	draw_map_ennemies(t_map_draw *draw, t_list *entities, t_image *img)
{
	t_mlx_coords	position;
	t_entity		*entity;

	while (entities != NULL)
	{
		entity = (t_entity *) entities->content;
		get_coords(&entity->sprite->position, &position, draw->tile_size, \
			&draw->coords);
		t_mlx_draw_disk(img, &position, draw->element_radius, \
			MAP_DRAW_COL_ENNEMIES);
		entities = entities->next;
	}
}

void	draw_map_entities(t_map_draw *draw, t_game *game)
{
	draw_map_rays(draw, &game->player, game->rays, game->mlx.img_buff);
	draw_map_player(draw, &game->player, game->mlx.img_buff);
	draw_map_ennemies(draw, game->entities, game->mlx.img_buff);
}
