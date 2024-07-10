/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/10 10:46:19 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mouse_press_handler(int button, int x, int y, t_game *data)
{
	if (button || data || x || y)
		return (0);
	return (1);
}
