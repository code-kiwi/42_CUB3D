/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_lvl1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:52:16 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 13:55:16 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

static bool	init_ui_lvl_btn6(
	t_ui *ui_lvl,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_LVL_BTN_W_RATIO * ui_lvl->size.x;
	btn->size.y = UI_LVL_BTN_H_RATIO * ui_lvl->size.y;
	btn->pos.x = ui_lvl->pos.x + 10;
	btn->pos.y = ui_lvl->pos.y + ui_lvl->size.y - btn->size.y - 10;
	btn->texture_off = anim[IDX_TXTR_UI_LVL_BTN_PREV_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_LVL_BTN_PREV_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

static bool	init_ui_lvl_buttons(
	t_ui *ui_lvl,
	void *mlx,
	t_animation anim[MAP_NB_IDS]
)
{
	ui_lvl->buttons = (t_button *)ft_calloc(ui_lvl->nb_buttons, \
		sizeof(t_button));
	if (ui_lvl->buttons == NULL)
		return (false);
	if (
		!init_ui_lvl_btn1(ui_lvl, &ui_lvl->buttons[0], mlx, anim)
		|| !init_ui_lvl_btn2(ui_lvl, &ui_lvl->buttons[1], mlx, anim)
		|| !init_ui_lvl_btn3(ui_lvl, &ui_lvl->buttons[2], mlx, anim)
		|| !init_ui_lvl_btn4(ui_lvl, &ui_lvl->buttons[3], mlx, anim)
		|| !init_ui_lvl_btn5(ui_lvl, &ui_lvl->buttons[4], mlx, anim)
		|| !init_ui_lvl_btn6(ui_lvl, &ui_lvl->buttons[5], mlx, anim)
	)
	{
		free(ui_lvl->buttons);
		ui_lvl->buttons = NULL;
		return (false);
	}
	return (true);
}

static bool	init_ui_lvl_label(
	t_ui *ui_lvl,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	t_dimension	dim;

	ui_lvl->labels = (t_label *)ft_calloc(ui_lvl->nb_labels, \
		sizeof(t_label));
	if (ui_lvl->labels == NULL)
		return (false);
	dim.size.x = UI_LVL_LBL_W_RATIO * ui_lvl->size.x;
	dim.size.y = UI_LVL_LBL_H_RATIO * ui_lvl->size.y;
	dim.coords.x = ui_lvl->pos.x + (ui_lvl->size.x / 2 \
		- dim.size.x / 2);
	dim.coords.y = ui_lvl->pos.y + ui_lvl->size.y / 10;
	if (!init_label(&ui_lvl->labels[0], &dim, \
		anim[IDX_TXTR_UI_LVL_LBL].textures->content, mlx_ptr))
	{
		free(ui_lvl->labels);
		ui_lvl->labels = NULL;
		return (false);
	}
	return (true);
}

bool	init_ui_lvl(
	t_ui *ui_lvl,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	if (ui_lvl == NULL || mlx_ptr == NULL)
		return (false);
	ui_lvl->texture = \
		(t_image *) anim[IDX_TXTR_UI_LVL_BG].textures->content;
	ui_lvl->size.x = (int)((float)WIN_WIDTH * UI_LVL_W_RATIO);
	ui_lvl->size.y = (int)((float)WIN_HEIGHT * UI_LVL_H_RATIO);
	ui_lvl->pos.x = (WIN_WIDTH - ui_lvl->size.x) / 2;
	ui_lvl->pos.y = (WIN_HEIGHT - ui_lvl->size.y) / 2;
	ui_lvl->nb_buttons = UI_LVL_NB_BTN;
	if (!init_ui_lvl_buttons(ui_lvl, mlx_ptr, anim))
	{
		destroy_ui(ui_lvl, mlx_ptr);
		return (false);
	}
	ui_lvl->nb_labels = UI_LVL_NB_LBL;
	if (!init_ui_lvl_label(ui_lvl, mlx_ptr, anim))
	{
		destroy_ui(ui_lvl, mlx_ptr);
		return (false);
	}
	return (true);
}
