/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:02:47 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 17:52:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"
#include "mlx.h"

bool	t_mlx_add_hook(
	t_mlx *mlx, int (*handler)(void *), void *data, enum e_hook_type hook_type
)
{
	if (mlx == NULL || handler == NULL)
		return (false);
	if (hook_type == HOOK_DESTROY)
		mlx_hook(mlx->mlx_win, MLX_ON_DESTROY, (1L << 3), handler, data);
	else if (hook_type == HOOK_KEY)
		mlx_key_hook(mlx->mlx_win, handler, data);
	else if (hook_type == HOOK_MOUSE)
		mlx_mouse_hook(mlx->mlx_win, handler, data);
	else if (hook_type == HOOK_LOOP)
		mlx_loop_hook(mlx->mlx_ptr, handler, data);
	else
		return (false);
	mlx_loop_hook(mlx->mlx_ptr, handler, data);
	return (true);
}
