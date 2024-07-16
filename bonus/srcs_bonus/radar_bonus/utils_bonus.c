/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:53:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/16 14:54:56 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "mlx.h"
#include "libft.h"

bool	init_radar(t_radar *rad, t_mlx *mlx)
{
	if (rad == NULL || mlx == NULL)
		return (error_print(ERR_RADAR_CREATION), false);
	rad->radius = (int)((float)mlx->width / RADAR_SIZE_RATIO);
	rad->nb_tiles = RADAR_NB_TILES;
	rad->tile_size = 2 * rad->radius / rad->nb_tiles;
	rad->radius_element = rad->tile_size / 2 - 2;
	rad->draw_offset = (2 * rad->radius - rad->nb_tiles * rad->tile_size) / 2;
	rad->coords.x = RADAR_OFFSET;
	rad->coords.y = mlx->height - 2 * rad->radius - RADAR_OFFSET;
	rad->center.x = rad->radius;
	rad->center.y = rad->radius;
	rad->needs_update = false;
	rad->img = t_image_init(mlx->mlx_ptr, 2 * rad->radius, 2 * rad->radius);
	if (rad->img == NULL)
		return (error_print(ERR_RADAR_CREATION), false);
	t_image_colorize(rad->img, 0xFF000000);
	rad->tiles = create_str_array(rad->nb_tiles, rad->nb_tiles, '0');
	if (rad->tiles == NULL)
	{
		destroy_radar(rad, mlx->mlx_ptr);
		return (error_print(ERR_RADAR_CREATION), false);
	}
	return (true);
}

void	destroy_radar(t_radar *radar, void *mlx_ptr)
{
	if (radar == NULL)
		return ;
	if (radar->img != NULL)
	{
		t_image_destroy(mlx_ptr, radar->img, true);
		radar->img = NULL;
	}
	if (radar->tiles != NULL)
		ft_free_str_array(&radar->tiles);
}
