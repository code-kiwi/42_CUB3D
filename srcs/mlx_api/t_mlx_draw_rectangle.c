/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_rectangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:24:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 15:43:37 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "mlx_api.h"

bool	t_mlx_draw_rectangle(
	t_image *img,
	t_mlx_coords coords,
	t_mlx_coords size,
	unsigned int color
)
{
	int	row;

	if (
		img == NULL || coords.x < 0 || coords.x > img->width || coords.y < 0
		|| coords.y > img->height || size.x < 0 || size.y < 0
	)
		return (false);
	row = 0;
	while (row < size.y)
	{
		if (!t_mlx_draw_line(img, coords, \
				(t_mlx_coords){coords.x + size.x, coords.y}, color))
			return (false);
		coords.y++;
		row++;
	}
	return (true);
}
