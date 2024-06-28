/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_shoot_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:04:59 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/28 08:45:31 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "mlx_api_bonus.h"
#include "libft.h"

void	player_shoot(t_game *game)
{
	t_player_display	*display;

	if (game == NULL)
		return ;
	display = &game->player.display;
	display->frame_curr = display->frames->next;
	display->frame_update_delta = 0;
}
