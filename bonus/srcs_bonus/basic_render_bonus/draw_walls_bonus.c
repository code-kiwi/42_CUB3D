/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/09/02 13:04:09 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <pthread.h>

#include "libft.h"
#include "door_bonus.h"

static void	*draw_thread_routine(void *param)
{
	t_draw_thread_arg	*thread_arg;

	if (param == NULL)
		return (NULL);
	thread_arg = (t_draw_thread_arg *) param;
	draw_walls_part(thread_arg->game, thread_arg->start, thread_arg->end);
	return (NULL);
}

bool	draw_walls(t_game *game)
{
	size_t				i;
	size_t				j;
	bool				error;

	error = false;
	i = 0;
	while (i < NB_DRAW_THREADS)
	{
		if (pthread_create(&game->threads[i], NULL, draw_thread_routine, \
			&game->draw_thread_args[i]) != 0)
		{
			error = true;
			break ;
		}
		i++;
	}
	j = 0;
	while (j < i)
	{
		if (pthread_join(game->threads[j], NULL))
			error = true;
		j++;
	}
	return (i == NB_DRAW_THREADS && !error);
}
