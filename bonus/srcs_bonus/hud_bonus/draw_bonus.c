/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:47:29 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/26 10:14:26 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_bonus.h"
#include "hud_bonus.h"

void	draw_hud(t_game *game, t_hud *hud)
{
	t_mlx_coords	bar_size;

	if (game == NULL || hud == NULL)
		return ;
	t_mlx_draw_rect_texture(game->mlx.img_buff, &hud->pos, &hud->size, \
		hud->texture_bg);
	t_mlx_draw_rect_texture(game->mlx.img_buff, &hud->health_lbl_pos, \
		&hud->health_lbl_size, hud->texture_lbl_health);
	t_mlx_draw_rect_texture(game->mlx.img_buff, &hud->weapon_lbl_pos, \
		&hud->weapon_lbl_size, hud->texture_lbl_weapon);
	t_mlx_draw_rectangle(game->mlx.img_buff, &hud->health_bar_pos, \
		&hud->health_bar_size, HUD_HEALTH_BAR_COL_BG);
	t_mlx_draw_rectangle(game->mlx.img_buff, &hud->weapon_bar_pos, \
		&hud->weapon_bar_size, HUD_WEAPON_BAR_COL_BG);
	bar_size.x = ((float)game->player.health_point / PLAYER_HEALTH_POINT) * hud->health_bar_size.x;
	bar_size.y = hud->health_bar_size.y;
	t_mlx_draw_rectangle(game->mlx.img_buff, &hud->health_bar_pos, \
		&bar_size, HUD_HEALTH_BAR_COL);
	bar_size.x = ((float)game->player.weapon_info.curr_weapon->remaining_use / game->player.weapon_info.curr_weapon->load_capacity) * hud->weapon_bar_size.x;
	bar_size.y = hud->weapon_bar_size.y;
	t_mlx_draw_rectangle(game->mlx.img_buff, &hud->weapon_bar_pos, \
		&bar_size, HUD_WEAPON_BAR_COL);
	return ;
}

