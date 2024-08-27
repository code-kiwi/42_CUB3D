/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_mouse_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:38:35 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:14:23 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"

void	t_mlx_center_cursor(t_mlx *mlx)
{
	if (mlx == NULL || mlx->mlx_ptr == NULL || mlx->mlx_win == NULL)
		return ;
	mlx_mouse_move(mlx->mlx_ptr, mlx->mlx_win, mlx->width_half, \
		mlx->height_half);
}

void	t_mlx_mouse_show(t_mlx *mlx, bool *mouse_hidden)
{
	if (mlx == NULL || mouse_hidden == NULL || !*mouse_hidden)
		return ;
	*mouse_hidden = false;
	mlx_mouse_show(mlx->mlx_ptr, mlx->mlx_win);
	t_mlx_center_cursor(mlx);
}

void	t_mlx_mouse_hide(t_mlx *mlx, bool *mouse_hidden)
{
	if (mlx == NULL || mouse_hidden == NULL || *mouse_hidden)
		return ;
	*mouse_hidden = true;
	mlx_mouse_hide(mlx->mlx_ptr, mlx->mlx_win);
	t_mlx_center_cursor(mlx);
}
