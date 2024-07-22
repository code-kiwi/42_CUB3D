/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_positions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:32:58 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/22 14:44:45 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_bonus.h"
#include "weapons_bonus.h"
#include "libft.h"

void	set_weapon_positions(t_weapon *weapon, t_game *game)
{
	if (game == NULL || weapon == NULL)
		return ;
	weapon->coords.x = (game->mlx.width - weapon->curr_frame->width) / 2;
	weapon->coords.y = game->mlx.height - weapon->curr_frame->height;
	weapon->size.x = weapon->curr_frame->width;
	weapon->size.y = weapon->curr_frame->height;
}
