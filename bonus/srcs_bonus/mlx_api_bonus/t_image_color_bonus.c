/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:24:47 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/19 10:30:12 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

#include "mlx_api_bonus.h"

void	t_image_colorize(t_image *img, uint32_t color)
{
	int				x;
	int				y;
	unsigned int	*img_addr;

	if (img == NULL)
		return ;
	img_addr = (unsigned int *) img->addr;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			*(img_addr + y * img->width + x) = color;
			x++;
		}
		y++;
	}
}

void	t_image_multiply_each_px(t_image *img, float factor)
{
	int				x;
	int				y;
	unsigned int	*img_addr;

	if (img == NULL)
		return ;
	img_addr = (unsigned int *) img->addr;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			multiply_color(img_addr + y * img->width + x, factor);
			x++;
		}
		y++;
	}
}
