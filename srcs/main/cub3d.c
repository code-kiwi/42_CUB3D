/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 15:02:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "mlx_api.h"

#include "mlx.h"

int	main(void)
{
	t_mlx	mlx;

	t_mlx_init(&mlx, WIN_WIDTH, WIN_HEIGHT, "test");
	mlx_loop_hook(mlx.mlx_ptr, game_loop, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
