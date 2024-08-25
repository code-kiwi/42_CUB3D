/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:47:38 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/25 19:24:08 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_bonus.h"
#include "hud_bonus.h"
#include "libft.h"

bool	init_hud(t_game *game, t_hud *hud)
{
	if (game == NULL || hud == NULL)
		return (false);
	hud->size.x = HUD_W_RATIO * game->mlx.width;
	hud->size.y = HUD_H_RATIO * game->mlx.height;
	hud->pos.x = game->mlx.width - hud->size.x;
	hud->pos.y = game->mlx.height - hud->size.y;
	hud->texture_bg = game->anim[IDX_TXTR_HUD_BG].textures->content;
	if (!t_image_resize(game->mlx.mlx_ptr, hud->texture_bg, &hud->size))
		return (false);
	return (true);
}
