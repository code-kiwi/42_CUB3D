/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_lvl2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:52:16 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 13:55:11 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

bool	init_ui_lvl_btn1(
	t_ui *ui_lvl,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_LVL_BTN_W_RATIO * ui_lvl->size.x;
	btn->size.y = UI_LVL_BTN_H_RATIO * ui_lvl->size.y;
	btn->pos.x = ui_lvl->pos.x \
		+ (ui_lvl->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_lvl->pos.y + 3 * ui_lvl->size.y / 10;
	btn->texture_off = anim[IDX_TXTR_UI_LVL_BTN1_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_LVL_BTN1_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

bool	init_ui_lvl_btn2(
	t_ui *ui_lvl,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_LVL_BTN_W_RATIO * ui_lvl->size.x;
	btn->size.y = UI_LVL_BTN_H_RATIO * ui_lvl->size.y;
	btn->pos.x = ui_lvl->pos.x \
		+ (ui_lvl->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_lvl->pos.y + 4 * ui_lvl->size.y / 10;
	btn->texture_off = anim[IDX_TXTR_UI_LVL_BTN2_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_LVL_BTN2_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

bool	init_ui_lvl_btn3(
	t_ui *ui_lvl,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_LVL_BTN_W_RATIO * ui_lvl->size.x;
	btn->size.y = UI_LVL_BTN_H_RATIO * ui_lvl->size.y;
	btn->pos.x = ui_lvl->pos.x \
		+ (ui_lvl->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_lvl->pos.y + 5 * ui_lvl->size.y / 10;
	btn->texture_off = anim[IDX_TXTR_UI_LVL_BTN3_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_LVL_BTN3_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

bool	init_ui_lvl_btn4(
	t_ui *ui_lvl,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_LVL_BTN_W_RATIO * ui_lvl->size.x;
	btn->size.y = UI_LVL_BTN_H_RATIO * ui_lvl->size.y;
	btn->pos.x = ui_lvl->pos.x \
		+ (ui_lvl->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_lvl->pos.y + 6 * ui_lvl->size.y / 10;
	btn->texture_off = anim[IDX_TXTR_UI_LVL_BTN4_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_LVL_BTN4_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

bool	init_ui_lvl_btn5(
	t_ui *ui_lvl,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_LVL_BTN_W_RATIO * ui_lvl->size.x;
	btn->size.y = UI_LVL_BTN_H_RATIO * ui_lvl->size.y;
	btn->pos.x = ui_lvl->pos.x \
		+ (ui_lvl->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_lvl->pos.y + 7 * ui_lvl->size.y / 10;
	btn->texture_off = anim[IDX_TXTR_UI_LVL_BTN5_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_LVL_BTN5_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}
