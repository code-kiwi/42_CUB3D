/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/19 11:59:51 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>

#include "libft.h"
#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		error_print(ERR_PROG_ARGS);
		return (EXIT_FAILURE);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!read_map(&game.map, argv[1]) || !t_game_init(&game))
	{
		t_game_destroy(&game);
		return (EXIT_FAILURE);
	}
	mlx_loop(game.mlx.mlx_ptr);
	t_game_destroy(&game);
	return (0);
}
