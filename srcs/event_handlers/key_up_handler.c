/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_up_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:49:48 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 15:01:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"
#include "event_handlers.h"
#include "libft.h"

/**
 * @brief Handles the keyboard up key events
 * @param data The t_game which contains project data to affect
 * @param key The integer value of the pressed key
 * @return A dummy integer
*/
int	key_up_handler(int key, t_game *data)
{
	if (data == NULL)
		error_exit(NULL, ERR_ARG);
	if (key == KEY_ESC)
		return (destroy_handler(data));
	ft_printf("Key up: %d\n", key);
	return (0);
}
