/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:47:29 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/25 19:13:31 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_bonus.h"
#include "hud_bonus.h"

void	draw_hud(t_game *game, t_hud *hud)
{
	if (game == NULL || hud == NULL)
		return ;
	t_mlx_draw_rect_texture(game->mlx.img_buff, &hud->pos, &hud->size, hud->texture_bg);
	return ;
}

