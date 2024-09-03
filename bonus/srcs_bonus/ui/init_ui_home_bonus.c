/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_home_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:52:16 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/03 14:48:34 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

static bool	init_ui_home_btn1(
	t_ui *ui_home,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_HOME_BTN_W_RATIO * ui_home->size.x;
	btn->size.y = UI_HOME_BTN_H_RATIO * ui_home->size.y;
	btn->pos.x = ui_home->pos.x \
		+ (ui_home->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_home->pos.y + 5 * ui_home->size.y / 8;
	btn->texture_off = anim[IDX_TXTR_UI_HOME_BTN1_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_HOME_BTN1_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) game_reach_level_selection;
	return (true);
}

static bool	init_ui_home_btn2(
	t_ui *ui_home,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_HOME_BTN_W_RATIO * ui_home->size.x;
	btn->size.y = UI_HOME_BTN_H_RATIO * ui_home->size.y;
	btn->pos.x = ui_home->pos.x \
		+ (ui_home->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_home->pos.y + 6 * ui_home->size.y / 8;
	btn->texture_off = anim[IDX_TXTR_UI_HOME_BTN2_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_HOME_BTN2_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

static bool	init_ui_home_buttons(
	t_ui *ui_home,
	void *mlx,
	t_animation anim[MAP_NB_IDS]
)
{
	ui_home->buttons = (t_button *)ft_calloc(ui_home->nb_buttons, \
		sizeof(t_button));
	if (ui_home->buttons == NULL)
		return (false);
	if (
		!init_ui_home_btn1(ui_home, &ui_home->buttons[0], mlx, anim)
		|| !init_ui_home_btn2(ui_home, &ui_home->buttons[1], mlx, anim)
	)
	{
		free(ui_home->buttons);
		ui_home->buttons = NULL;
		return (false);
	}
	return (true);
}

static bool	init_ui_home_label(
	t_ui *ui_home,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	t_dimension	dim;

	ui_home->labels = (t_label *)ft_calloc(ui_home->nb_labels, \
		sizeof(t_label));
	if (ui_home->labels == NULL)
		return (false);
	dim.size.x = UI_HOME_LBL_W_RATIO * ui_home->size.x;
	dim.size.y = UI_HOME_LBL_H_RATIO * ui_home->size.y;
	dim.coords.x = ui_home->pos.x + (ui_home->size.x / 2 \
		- dim.size.x / 2);
	dim.coords.y = ui_home->pos.y + ui_home->size.y / 6;
	if (!init_label(&ui_home->labels[0], &dim, \
		anim[IDX_TXTR_UI_HOME_LBL].textures->content, mlx_ptr))
	{
		free(ui_home->labels);
		ui_home->labels = NULL;
		return (false);
	}
	return (true);
}

bool	init_ui_home(
	t_ui *ui_home,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	if (ui_home == NULL || mlx_ptr == NULL)
		return (false);
	ui_home->texture = \
		(t_image *) anim[IDX_TXTR_UI_HOME_BG].textures->content;
	ui_home->size.x = (int)((float)WIN_WIDTH * UI_HOME_W_RATIO);
	ui_home->size.y = (int)((float)WIN_HEIGHT * UI_HOME_H_RATIO);
	ui_home->pos.x = (WIN_WIDTH - ui_home->size.x) / 2;
	ui_home->pos.y = (WIN_HEIGHT - ui_home->size.y) / 2;
	ui_home->nb_buttons = UI_HOME_NB_BTN;
	if (!init_ui_home_buttons(ui_home, mlx_ptr, anim))
	{
		destroy_ui(ui_home, mlx_ptr);
		return (false);
	}
	ui_home->nb_labels = UI_HOME_NB_LBL;
	if (!init_ui_home_label(ui_home, mlx_ptr, anim))
	{
		destroy_ui(ui_home, mlx_ptr);
		return (false);
	}
	return (true);
}
