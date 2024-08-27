/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:55 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 11:51:45 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>

#include "libft.h"
#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"
#include "mlx.h"

// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	if (argc != 2)
// 	{
// 		error_print(ERR_PROG_ARGS);
// 		return (EXIT_FAILURE);
// 	}
// 	ft_memset(&game, 0, sizeof(t_game));
// 	if (!read_map(&game.map, argv[1], game.anim)
// 		|| !t_game_init(&game))
// 	{
// 		t_game_destroy(&game);
// 		return (EXIT_FAILURE);
// 	}
// 	mlx_loop(game.mlx.mlx_ptr);
// 	t_game_destroy(&game);
// 	return (0);
// }

#include "pathfinding_bonus.h"

#include <sys/time.h>

void	coords_print(void *value)
{
	t_mlx_coords	*coords;

	coords = value;
	printf("(%d,%d)\n", coords->x, coords->y);
}

void	checkPath(int start_x, int start_y, int end_x, int end_y, t_map *map)
{
	t_mlx_coords	start;
	t_mlx_coords	end;
	t_list			*path;
	struct timeval	startTime;
	struct timeval	endTime;
	float			elapsedTime;

	start.x = start_x;
	start.y = start_y;
	end.x = end_x;
	end.y = end_y;
	gettimeofday(&startTime, NULL);
	path = find_path(&start, &end, map);
	gettimeofday(&endTime, NULL);
	ft_lstprint(path, coords_print);
	ft_lstclear(&path, free);
    elapsedTime = (endTime.tv_sec - startTime.tv_sec) * 1000.0;
    elapsedTime += (endTime.tv_usec - startTime.tv_usec) / 1000.0;
	printf("pathfinding duration : %f\n", elapsedTime);
}

int	main(int argc, char **argv)
{
	t_game			game;

	if (argc != 2)
	{
		error_print(ERR_PROG_ARGS);
		return (EXIT_FAILURE);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!read_map(&game.map, argv[1], game.anim)
		|| !t_game_init(&game))
	{
		t_game_destroy(&game);
		return (EXIT_FAILURE);
	}
	checkPath(1, 1, 4, 1, &game.map);
	checkPath(1, 1, 10, 30, &game.map);
	checkPath(1, 1, 1, 4, &game.map);

	printf("Too much allocation\n");
	checkPath(1, 1, 10, 31, &game.map);

	printf("End in box\n");
	checkPath(1, 1, 15, 4, &game.map);

	printf("Start in box\n");
	checkPath(15, 4, 1, 1, &game.map);
	// mlx_loop(game.mlx.mlx_ptr);
	t_game_destroy(&game);
	return (0);
}
