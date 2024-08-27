/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:52:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 14:24:03 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

/**
 * @brief print a formated string err_msg containing a variable str
 */
void	error_print_string(char *err_msg, char *str)
{
	if (err_msg == NULL || str == NULL)
		return ;
	ft_dprintf(STDERR_FILENO, ERR_LITERALS_STR, err_msg, str);
}

/**
 * @brief Prints an error message on the appropriate file descriptor
 * @param err_msg The error message to print
 * @note If no message is provided, a standard message will be printed
*/
void	error_print(char *err_msg)
{
	if (err_msg != NULL)
		ft_dprintf(STDERR_FILENO, ERR_LITERALS, err_msg);
	else
		ft_dprintf(STDERR_FILENO, ERR_BASIC);
}

/**
 * @brief Destroys the given t_game pointer, prints the err_msg and exits
 * @param game The project's game to destroy
 * @param err_msg The error message to display
*/
void	error_exit(t_game *game, char *err_msg)
{
	if (game != NULL)
		t_game_destroy(game);
	if (err_msg != NULL)
		error_print(err_msg);
	exit(EXIT_FAILURE);
}
