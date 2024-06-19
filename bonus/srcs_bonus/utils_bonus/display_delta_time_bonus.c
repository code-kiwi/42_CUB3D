/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_delta_time_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:29:36 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/19 13:32:51 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

#include "cub3d_bonus.h"

void	display_delta_time(void)
{
	static long		last_tick = 0;
	long			curr_tick;
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		error_print("Impossible to get time of day");
		return ;
	}
	curr_tick = current_time.tv_sec * 1000000 + current_time.tv_usec;
	if (last_tick == 0)
	{
		last_tick = curr_tick;
		return ;
	}
	printf("Delta time: %ld\n", curr_tick - last_tick);
	last_tick = curr_tick;
}
