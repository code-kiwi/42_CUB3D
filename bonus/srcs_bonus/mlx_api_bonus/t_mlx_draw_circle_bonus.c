/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_circle_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:09:10 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/15 09:05:58 by mhotting         ###   ########.fr       */
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

static void	update_temp(t_mlx_coords *temp, int x, int y)
{
	temp->x = x;
	temp->y = y;
}

void	t_mlx_draw_circle(
	t_image *img,
	t_mlx_coords *coords,
	int radius,
	uint32_t color
)
{
	t_mlx_coords	xy;
	int				err;
	t_mlx_coords	temp;

	init_vars(&xy, &err, radius);
	while (xy.x >= xy.y)
	{
		update_temp(&temp, coords->x + xy.x, coords->y + xy.y);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x + xy.y, coords->y + xy.x);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x - xy.y, coords->y + xy.x);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x - xy.x, coords->y + xy.y);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x - xy.x, coords->y - xy.y);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x - xy.y, coords->y - xy.x);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x + xy.y, coords->y - xy.x);
		t_mlx_draw_pixel(img, &temp, color);
		update_temp(&temp, coords->x + xy.x, coords->y - xy.y);
		t_mlx_draw_pixel(img, &temp, color);
		update_err(&xy, &err);
	}
}
