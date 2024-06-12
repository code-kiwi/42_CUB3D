/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:36:36 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 17:31:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx_api.h"
#include "mlx.h"

void	t_mlx_destroy(t_mlx *mlx)
{
	if (mlx == NULL)
		return ;
	if (mlx->mlx_ptr != NULL && mlx->mlx_win != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	if (mlx->mlx_ptr != NULL && mlx->img1 != NULL)
		t_image_destroy(mlx->mlx_ptr, mlx->img1);
	if (mlx->mlx_ptr != NULL && mlx->img2 != NULL)
		t_image_destroy(mlx->mlx_ptr, mlx->img2);
	if (mlx->mlx_ptr != NULL)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
}
