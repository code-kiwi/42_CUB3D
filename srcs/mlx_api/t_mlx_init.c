/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:36:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/13 17:35:57 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx.h"
#include "mlx_api.h"
#include "libft.h"

/**
 * @brief Initializes the given t_mlx instance''s images
 * 
 * Both img1 and img2 will be initalized, the buffer image will be set as img2
 * @param mlx The t_mlx instance whose images will be initialized
 * @param img_width The image width
 * @param img_height The image height
 * @return true on SUCCESS, false on ERROR
*/
static bool	t_mlx_init_images(t_mlx *mlx, int img_width, int img_height)
{
	if (mlx == NULL || mlx->mlx_ptr == NULL || img_width < 0 || img_height < 0)
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
	mlx->img_buff = mlx->img2;
	return (true);
}

/**
 * @brief Initializes the given t_mlx instance
 * 
 * Steps:
 * 	- creates the mlx pointer
 * 	- creates the images
 * 	- creates the window
 * @param mlx The t_mlx instance to initialize
 * @param win_width The window width
 * @param win_height The window height
 * @param title The window title
 * @return true on SUCCESS, false on ERROR
*/
bool	t_mlx_init(t_mlx *mlx, int win_width, int win_height, char *title)
{
	if (mlx == NULL || win_width < 0 || win_height < 0)
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
