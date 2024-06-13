/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_draw_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:04:21 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 14:20:47 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx_api.h"
#include "mlx.h"

bool	t_mlx_draw_line(
	t_image *img,
	t_mlx_coords coords_start,
	t_mlx_coords coords_end,
	unsigned int color
)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;

	if (img == NULL)
		return (false);
	dx = abs(coords_end.x - coords_start.x);
	return (true);
}
