/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/17 11:29:01 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include "mlx_api.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (EXIT_FAILURE);
	ft_memset(&game, 0, sizeof(t_game));
	if (!read_map(&game.map, argv[1]))
	{
		error_print(ERR_MAP_READ);
		return (EXIT_FAILURE);
	}
	if (!t_game_init(&game))
		error_exit(&game, ERR_GAME_INIT);
	mlx_loop(game.mlx.mlx_ptr);
	t_game_destroy(&game);
	return (0);
}
