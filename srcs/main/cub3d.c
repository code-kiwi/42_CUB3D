/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 19:55:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "mlx_api.h"

#include "mlx.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (EXIT_FAILURE);
	ft_memset(&game, 0, sizeof(t_game));
	if (!read_map(&game.map, argv[1]))
		error_exit(&game, ERR_MAP_READ);
	if (!t_game_init(&game))
		error_exit(&game, ERR_GAME_INIT);
	cast_rays(&game.player, &game.map, game.rays);
	draw_walls(game.mlx.img_buff, game.rays);
	t_mlx_render(&game.mlx);
	mlx_loop(game.mlx.mlx_ptr);
	t_game_destroy(&game);
	return (0);
}
