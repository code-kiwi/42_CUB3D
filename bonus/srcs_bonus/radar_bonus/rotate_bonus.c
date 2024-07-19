/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:11:05 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/19 10:16:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"

static void	rotate_coord(
	t_mlx_coords *coords,
	t_mlx_coords *res_coords,
	int img_size,
	float orientation
)
{
	t_mlx_coords	tcoords;

	tcoords.x = coords->x - img_size / 2;
	tcoords.y = coords->y - img_size / 2;
	res_coords->x = (int)((float) tcoords.x * cos(orientation) - \
		(float) tcoords.y * sin(orientation));
	res_coords->y = (int)((float) tcoords.x * sin(orientation) + \
		(float) tcoords.y * cos(orientation));
}

static void	draw_radar_rotate_process(
	t_image *curr,
	t_image *res,
	int img_size,
	float orientation
)
{
	uint32_t		*curr_addr;
	uint32_t		*res_addr;
	t_mlx_coords	res_coords;
	t_mlx_coords	curr_coords;

	curr_addr = (uint32_t *) curr->addr;
	res_addr = (uint32_t *) res->addr;
	res_coords.x = 0;
	while (res_coords.x < img_size)
	{
		res_coords.y = 0;
		while (res_coords.y < img_size)
		{
			if (*(curr_addr + res_coords.x * img_size + res_coords.y) != \
				RAD_COL_TRANSPARENT)
			{
				rotate_coord(&res_coords, &curr_coords, img_size, orientation);
				*(res_addr + res_coords.x * img_size + res_coords.y) = \
					*(curr_addr + (curr_coords.x + img_size / 2) * img_size + \
					(curr_coords.y + img_size / 2));
			}
			res_coords.y++;
		}
		res_coords.x++;
	}
}

void	draw_radar_rotate(t_radar *radar)
{
	t_image	*curr;
	t_image	*res;

	curr = radar->img;
	res = radar->img2;
	draw_radar_rotate_process(curr, res, radar->radius * 2, radar->orientation);
	radar->img = res;
	radar->img2 = curr;
	return ;
}
