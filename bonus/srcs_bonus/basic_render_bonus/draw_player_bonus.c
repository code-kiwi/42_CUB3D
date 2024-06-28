/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:47:03 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/28 12:00:01 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_bonus.h"
#include "player_bonus.h"
#include "libft.h"

void	draw_player(t_game *game)
{
	t_player_display	*display;

	if (game == NULL)
		return ;
	display = &game->player.display;
	t_mlx_draw_rect_texture(game->mlx.img_buff, &display->coords, \
		&display->size, (t_image *) display->frame_curr->content);
	t_mlx_draw_rect_texture(game->mlx.img_buff, &display->target_coords, \
		&display->target_size, &display->target_texture);
}
