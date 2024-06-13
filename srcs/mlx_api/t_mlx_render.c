/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:49:37 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 12:42:19 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "mlx_api.h"
#include "mlx.h"

bool	t_mlx_render(t_mlx *mlx)
{
	if (mlx == NULL || mlx->img_buff == NULL)
		return (false);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, \
		mlx->img_buff->ptr, 0, 0);
	if (mlx->img_buff == mlx->img1)
		mlx->img_buff = mlx->img2;
	else
		mlx->img_buff = mlx->img1;
	t_image_clear(mlx->img_buff);
	return (true);
}
