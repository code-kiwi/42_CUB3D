/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:25:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/19 15:33:14 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>

long	get_tick(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
		return (-1);
	return (current_time.tv_sec * 1000000 + current_time.tv_usec);
}
