/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_mouse_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:38:35 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/09 11:02:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "cub3d_bonus.h"
#include "mlx.h"

void	t_mlx_mouse_show(t_mlx *mlx, bool *mouse_hidden)
{
	if (mlx == NULL || mouse_hidden == NULL || !*mouse_hidden)
		return ;
	*mouse_hidden = false;
	mlx_mouse_show(mlx->mlx_ptr, mlx->mlx_win);
	mlx_mouse_move(mlx->mlx_ptr, mlx->mlx_win, mlx->width / 2, mlx->height / 2);
}

void	t_mlx_mouse_hide(t_mlx *mlx, bool *mouse_hidden)
{
	if (mlx == NULL || mouse_hidden == NULL || *mouse_hidden)
		return ;
	*mouse_hidden = true;
	mlx_mouse_hide(mlx->mlx_ptr, mlx->mlx_win);
}
