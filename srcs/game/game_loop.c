/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/19 09:07:52 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "mlx_api.h"
#include "libft.h"

#include <stdio.h>
#include <sys/time.h>

/**
 * @brief The main function called at each game loop iteration
 * @param game The project's game
 * @return A dummy integer
*/

long	get_time_diff(struct timeval *start, struct timeval *end)
{
	long	result;

	result = (end->tv_sec - start->tv_sec) * 1000000;
	result += end->tv_usec - start->tv_usec;
	return (result);
}

int	game_loop(t_game *game)
{
	struct timeval	start;
	struct timeval	end;

	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game->mlx.event_loop_counter++;
	if (game->mlx.event_loop_counter >= EVENT_LOOP_FRAME_TARGET)
	{
		gettimeofday(&start, NULL);
		update_player(&game->player, &game->map);
		if (!is_in_bounds(&game->player.position, &game->map))
			error_exit(game, ERR_PLAYER_QUIT_MAP);
		if (!cast_rays(&game->player, &game->map, game->rays))
			error_exit(game, ERR_CAST_RAYS);
		draw_walls(game);
		if (!t_mlx_render(&game->mlx))
			error_exit(game, ERR_RENDER);
		game->mlx.event_loop_counter = 0;
		gettimeofday(&end, NULL);
		printf ("delta : %ld\n", get_time_diff(&start, &end));
	}
	return (0);
}
