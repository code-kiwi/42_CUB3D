/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radar_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:53:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/15 14:15:05 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "mlx.h"
#include "libft.h"

bool	init_radar(t_radar *radar, t_mlx *mlx)
{
	if (radar == NULL || mlx == NULL)
		return (error_print(ERR_RADAR_CREATION), false);
	radar->radius = (int)((float)mlx->width / RADAR_SIZE_RATIO);
	radar->img = t_image_init(mlx->mlx_ptr, 2 * radar->radius, \
		2 * radar->radius);
	if (radar->img == NULL)
		return (error_print(ERR_RADAR_CREATION), false);
	t_image_colorize(radar->img, 0xFF000000);
	radar->tiles = create_str_array(RADAR_TILES_SIZE, RADAR_TILES_SIZE, '0');
	if (radar->tiles == NULL)
	{
		destroy_radar(radar, mlx->mlx_ptr);
		return (error_print(ERR_RADAR_CREATION), false);
	}
	radar->tiles_size = RADAR_TILES_SIZE;
	radar->coords.x = RADAR_OFFSET;
	radar->coords.y = mlx->height - 2 * radar->radius - RADAR_OFFSET;
	radar->color_bg = RADAR_COLOR_BG;
	radar->center.x = radar->radius;
	radar->center.y = radar->radius;
	radar->needs_update = false;
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
