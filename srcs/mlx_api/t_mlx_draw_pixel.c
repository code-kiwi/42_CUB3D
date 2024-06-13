/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:08:26 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 13:58:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"
#include "mlx.h"

bool	t_mlx_draw_pixel(t_image *img, t_mlx_coords coords, unsigned int color)
{
	char	*dest;

	if (img == NULL)
		return (false);
	if (
		coords.x < 0 || coords.x >= img->width
		|| coords.y < 0 || coords.y > img->height
	)
		return (true);
	dest = img->addr + (coords.y * img->line_len + coords.x * img->bpp / 8);
	*(unsigned int *) dest = color;
	return (true);
}
