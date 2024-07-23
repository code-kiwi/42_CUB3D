/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:57:37 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/23 12:42:08 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "weapons_bonus.h"
#include "libft.h"

void	draw_player(t_game *game, t_player *player)
{
	t_weapon	*weapon;

	if (game == NULL || player == NULL || player->curr_weapon == NULL)
		return ;
	weapon = player->curr_weapon;
	t_mlx_draw_rect_texture(game->mlx.img_buff, &weapon->coords, &weapon->size, \
		weapon->curr_frame);
	if (player->curr_weapon->target != NULL)
		t_mlx_draw_rect_texture(game->mlx.img_buff, &weapon->target_coords, \
			&weapon->target_size, weapon->target);
}
