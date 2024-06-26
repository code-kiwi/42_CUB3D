/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:45:49 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/14 12:32:38 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "cub3d.h"

/**
 * @brief Destroys the given t_game instance and exits the program
 * @param game The t_game instance to destroy before exiting
 * @return A dummy integer
*/
int	destroy_handler(t_game *game)
{
	if (game == NULL)
		error_exit(NULL, ERR_ARG);
	t_game_destroy(game);
	exit(EXIT_SUCCESS);
	return (0);
}
