/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_win_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:23:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/27 16:17:49 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "ui_bonus.h"
#include "libft.h"

static bool	init_ui_win_btn(
	t_ui *ui_win,
	t_button *btn,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	btn->size.x = UI_WIN_BTN_W_RATIO * ui_win->size.x;
	btn->size.y = UI_WIN_BTN_H_RATIO * ui_win->size.y;
	btn->pos.x = ui_win->pos.x + (ui_win->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_win->pos.y + 3 * ui_win->size.y \
		/ 12 + ui_win->labels[0].size.y + ui_win->labels[1].size.y;
	btn->texture_off = anim[IDX_TXTR_UI_WIN_BTN_OFF].textures->content;
	btn->texture_on = anim[IDX_TXTR_UI_WIN_BTN_ON].textures->content;
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

static bool	init_ui_win_button(
	t_ui *ui_win,
	void *mlx,
	t_animation anim[MAP_NB_IDS]
)
{
	ui_win->buttons = (t_button *)ft_calloc(ui_win->nb_buttons, \
		sizeof(t_button));
	if (ui_win->buttons == NULL)
		return (false);
	if (!init_ui_win_btn(ui_win, &ui_win->buttons[0], mlx, anim))
	{
		free(ui_win->buttons);
		ui_win->buttons = NULL;
		return (false);
	}
	return (true);
}

static void	free_label(t_ui *ui_win)
{
	free(ui_win->labels);
	ui_win->labels = NULL;
}

static bool	init_ui_win_labels(
	t_ui *ui_win,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	t_dimension	dim;

	ui_win->labels = (t_label *)ft_calloc(ui_win->nb_labels, sizeof(t_label));
	if (ui_win->labels == NULL)
		return (false);
	dim.size.x = UI_WIN_LBL_W_RATIO * ui_win->size.x;
	dim.size.y = UI_WIN_LBL_H_RATIO * ui_win->size.y;
	dim.coords.x = ui_win->pos.x + (ui_win->size.x / 2 - dim.size.x / 2);
	dim.coords.y = ui_win->pos.y + ui_win->size.y / 12;
	if (!init_label(&ui_win->labels[0], &dim, \
		anim[IDX_TXTR_UI_WIN_LABEL].textures->content, mlx_ptr))
		return (free_label(ui_win), false);
	dim.size.x = UI_WIN_LBL_TROPHY_W_RATIO * ui_win->size.x;
	dim.size.y = UI_WIN_LBL_TROPHY_H_RATIO * ui_win->size.y;
	dim.coords.x = ui_win->pos.x + (ui_win->size.x / 2 - dim.size.x / 2);
	dim.coords.y = ui_win->pos.y + 2 * ui_win->size.y \
		/ 12 + ui_win->labels[0].size.y;
	if (!init_label(&ui_win->labels[1], &dim, \
		anim[IDX_TXTR_UI_WIN_TROPHY].textures->content, mlx_ptr))
		return (free_label(ui_win), false);
	return (true);
}

bool	init_ui_win(
	t_ui *ui_win,
	void *mlx_ptr,
	t_animation anim[MAP_NB_IDS]
)
{
	if (ui_win == NULL || mlx_ptr == NULL)
		return (false);
	ui_win->texture = \
		(t_image *) anim[IDX_TXTR_UI_WIN_BG].textures->content;
	ui_win->size.x = (int)((float)WIN_WIDTH * UI_WIN_W_RATIO);
	ui_win->size.y = (int)((float)WIN_HEIGHT * UI_WIN_H_RATIO);
	ui_win->pos.x = (WIN_WIDTH - ui_win->size.x) / 2;
	ui_win->pos.y = (WIN_HEIGHT - ui_win->size.y) / 2;
	ui_win->nb_labels = UI_WIN_NB_LBL;
	if (!init_ui_win_labels(ui_win, mlx_ptr, anim))
	{
		destroy_ui(ui_win, mlx_ptr);
		return (false);
	}
	ui_win->nb_buttons = UI_WIN_NB_BTN;
	if (!init_ui_win_button(ui_win, mlx_ptr, anim))
	{
		destroy_ui(ui_win, mlx_ptr);
		return (false);
	}
	return (true);
}
