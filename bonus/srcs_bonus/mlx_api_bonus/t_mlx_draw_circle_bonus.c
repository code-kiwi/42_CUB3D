/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_circle_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:09:10 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/14 23:43:11 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

void	t_mlx_draw_circle(
	t_image *img,
	t_mlx_coords *coords,
	int radius,
	uint32_t color
)
{
	int				x;
	int				y;
	int				err;
	t_mlx_coords	temp;

	x = radius;
	y = 0;
	err = 0;
	while (x >= y)
	{
		temp.x = coords->x + x;
		temp.y = coords->y + y;
		t_mlx_draw_pixel(img, &temp, color);
		temp.x = coords->x + y;
		temp.y = coords->y + x;
		t_mlx_draw_pixel(img, &temp, color);
		temp.x = coords->x - y;
		temp.y = coords->y + x;
		t_mlx_draw_pixel(img, &temp, color);
		temp.x = coords->x - x;
		temp.y = coords->y + y;
		t_mlx_draw_pixel(img, &temp, color);
		temp.x = coords->x - x;
		temp.y = coords->y - y;
		t_mlx_draw_pixel(img, &temp, color);
		temp.x = coords->x - y;
		temp.y = coords->y - x;
		t_mlx_draw_pixel(img, &temp, color);
		temp.x = coords->x + y;
		temp.y = coords->y - x;
		t_mlx_draw_pixel(img, &temp, color);
		temp.x = coords->x + x;
		temp.y = coords->y - y;
		t_mlx_draw_pixel(img, &temp, color);
		if (err <= 0)
		{
			y += 1;
			err += 2 * y + 1;
		}
		if (err > 0)
		{
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}
