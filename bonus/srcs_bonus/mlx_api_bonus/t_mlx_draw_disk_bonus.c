/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_disk_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:53:10 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/14 23:41:56 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

static void	update_err(t_mlx_coords *xy, int *err)
{
	if (*err <= 0)
	{
		xy->y += 1;
		*err += 2 * xy->y + 1;
	}
	if (*err > 0)
	{
		xy->x -= 1;
		*err -= 2 * xy->x + 1;
	}
}

static void	init_vars(t_mlx_coords *xy, int *err, int radius)
{
	xy->x = radius;
	xy->y = 0;
	*err = 0;
}

void	t_mlx_draw_disk(
	t_image *img,
	t_mlx_coords *coords,
	int radius,
	uint32_t color
)
{
	int				err;
	t_mlx_coords	xy;
	t_mlx_coords	temp;

	init_vars(&xy, &err, radius);
	while (xy.x >= xy.y)
	{
		temp.x = coords->x - xy.x - 1;
		while (++temp.x <= coords->x + xy.x)
		{
			temp.y = coords->y + xy.y;
			t_mlx_draw_pixel(img, &temp, color);
			temp.y = coords->y - xy.y;
			t_mlx_draw_pixel(img, &temp, color);
		}
		temp.x = coords->x - xy.y - 1;
		while (++temp.x <= coords->x + xy.y)
		{
			temp.y = coords->y + xy.x;
			t_mlx_draw_pixel(img, &temp, color);
			temp.y = coords->y - xy.x;
			t_mlx_draw_pixel(img, &temp, color);
		}
		update_err(&xy, &err);
	}
}
