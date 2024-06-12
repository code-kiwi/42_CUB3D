/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:36:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 12:21:22 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "mlx_api.h"
#include "libft.h"

static bool t_mlx_init_images(t_mlx *mlx, size_t img_width, size_t img_height)
{
    if (mlx == NULL || mlx->mlx_ptr == NULL)
        return (false);
    mlx->img1 = t_image_init(mlx->mlx_ptr, img_width, img_height);
	if (mlx->img1 == NULL)
		return (false);
	mlx->img2 = t_image_init(mlx->mlx_ptr, img_width, img_height);
	if (mlx->img2 == NULL)
	{
		t_image_destroy(mlx->mlx_ptr, mlx->img1);
		mlx->img1 = NULL;
		return (false);
	}
	return (true);
}

bool    t_mlx_init(t_mlx *mlx, size_t win_width, size_t win_height, char *title)
{
    if (mlx == NULL)
        return (false);
    ft_memset(mlx, 0, sizeof(t_mlx));
    mlx->mlx_ptr = mlx_init();
    if (mlx->mlx_ptr == NULL)
        return (false);
    if (!t_mlx_init_images(mlx, win_width, win_height))
    {
        t_mlx_destroy(mlx);
        return (false);
    }
    mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, win_width, win_height, title);
    if (mlx->mlx_win == NULL)
    {
        t_mlx_destroy(mlx);
		return (false);
    }
    return (true);
}