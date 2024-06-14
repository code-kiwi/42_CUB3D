/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_down_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:49:41 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 15:02:07 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "event_handlers.h"
#include "libft.h"

/**
 * @brief Handles the keyboard down key events
 * @param data The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_down_handler(int key, t_game *data)
{
	if (data == NULL)
		error_exit(NULL, ERR_ARG);
	ft_printf("Key down: %d\n", key);
	return (0);
}
