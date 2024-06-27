/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/27 10:50:01 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>

#include "libft.h"
#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "mlx.h"

void	print_path(void *path_node)
{
	t_mlx_coords	*node;

	node = path_node;
	printf("position : (%d,%d)\n", node->x, node->y);
}

int	main(int argc, char **argv)
{
	t_game			game;
	t_mlx_coords	end;
	t_list			*path;
	t_mlx_coords	start;
	long			tick;

	if (argc != 2)
	{
		error_print(ERR_PROG_ARGS);
		return (EXIT_FAILURE);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!read_map(&game.map, argv[1]))
	{
		t_game_destroy(&game);
		return (EXIT_FAILURE);
	}
	start = (t_mlx_coords){1, 1};
	end = (t_mlx_coords){3, 9};
	tick = get_tick();
	path = find_path(&start, &end, &game.map);
	printf("delta : %ld\n", get_tick() - tick);
	ft_lstclear(&path, free);
	ft_lstprint(path, print_path);
	// mlx_loop(game.mlx.mlx_ptr);
	t_game_destroy(&game);
	return (0);
}
