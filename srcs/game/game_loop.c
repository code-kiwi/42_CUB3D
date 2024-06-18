/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:50:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/18 13:41:36 by brappo           ###   ########.fr       */
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

struct timeval	get_time_stamp(void)
{
    struct timeval	tv;

    gettimeofday(&tv,NULL);
    return (tv);
}

int	game_loop(t_game *game)
{
	suseconds_t	current_time;

	if (game == NULL)
		error_exit(game, ERR_GAME_LOOP);
	game->mlx.event_loop_counter++;
	if (game->mlx.event_loop_counter >= EVENT_LOOP_FRAME_TARGET)
	{
		update_player(&game->player, &game->map);
		current_time = get_time_stamp().tv_usec;
		if (!cast_rays(&game->player, &game->map, game->rays))
			error_exit(game, ERR_CAST_RAYS);
		draw_walls(game);
		printf ("delta : %ld\n", get_time_stamp().tv_usec - current_time);
		if (!t_mlx_render(&game->mlx))
			error_exit(game, ERR_RENDER);
		game->mlx.event_loop_counter = 0;
	}
	return (0);
}
