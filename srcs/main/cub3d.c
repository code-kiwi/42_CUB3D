/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 16:30:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "mlx_api.h"

#include "mlx.h"

int	main(void)
{
	t_cub_data	data;

	if (!t_cub_data_init(&data))
		error_exit(&data, ERR_MSG_DATA_INIT);
	if (!t_mlx_init(&data.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE))
		error_exit(&data, ERR_MSG_MLX_INIT);
	mlx_loop_hook(data.mlx.mlx_ptr, game_loop, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
