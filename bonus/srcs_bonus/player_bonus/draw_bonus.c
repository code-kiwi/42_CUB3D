/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:37 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/22 14:40:01 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "weapons_bonus.h"
#include "libft.h"

void	draw_player(t_game *game, t_player *player)
{
	if (game == NULL || player == NULL || player->curr_weapon == NULL)
		return ;
	t_mlx_draw_rect_texture(
		game->mlx.img_buff, &player->curr_weapon->coords,
			&player->curr_weapon->size, player->curr_weapon->curr_frame);
}
