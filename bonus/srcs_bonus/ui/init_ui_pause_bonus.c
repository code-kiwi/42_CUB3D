/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_pause_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:12 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/10 14:50:39 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "cub3d_bonus.h"
#include "event_handlers_bonus.h"
#include "ui_bonus.h"
#include "libft.h"

static bool	init_ui_pause_button1(t_ui *ui_pause, t_button *btn, void *mlx_ptr)
{
	btn->size.x = UI_PAUSE_BTN1_W_RATIO * ui_pause->size.x;
	btn->size.y = UI_PAUSE_BTN1_H_RATIO * ui_pause->size.y;
	btn->pos.x = ui_pause->pos.x + (ui_pause->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_pause->pos.y + 2 * ui_pause->size.y / 5;
	if (!t_image_import_file(&btn->texture_off, \
		UI_PAUSE_BTN1_OFF_FILE, mlx_ptr, &btn->size))
		return (false);
	if (!t_image_import_file(&btn->texture_on, UI_PAUSE_BTN1_ON_FILE, mlx_ptr, \
		&btn->size))
	{
		t_image_destroy(mlx_ptr, &btn->texture_off, false);
		return (false);
	}
	btn->texture_active = &btn->texture_off;
	btn->callback = (void (*)(void *)) game_pause_close;
	return (true);
}

static bool	init_ui_pause_button2(t_ui *ui_pause, t_button *btn, void *mlx_ptr)
{
	btn->size.x = UI_PAUSE_BTN2_W_RATIO * ui_pause->size.x;
	btn->size.y = UI_PAUSE_BTN2_H_RATIO * ui_pause->size.y;
	btn->pos.x = ui_pause->pos.x + (ui_pause->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_pause->pos.y + 3 * ui_pause->size.y / 5;
	if (!t_image_import_file(&btn->texture_off, \
		UI_PAUSE_BTN2_OFF_FILE, mlx_ptr, &btn->size))
		return (false);
	if (!t_image_import_file(&btn->texture_on, \
		UI_PAUSE_BTN2_ON_FILE, mlx_ptr, &btn->size))
	{
		t_image_destroy(mlx_ptr, &btn->texture_off, false);
		return (false);
	}
	btn->texture_active = &btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

static bool	init_ui_pause_buttons(t_ui *ui_pause, void *mlx_ptr)
{
	ui_pause->buttons = (t_button *)ft_calloc(ui_pause->nb_buttons, \
		sizeof(t_button));
	if (ui_pause->buttons == NULL)
		return (false);
	if (
		!init_ui_pause_button1(ui_pause, &ui_pause->buttons[0], mlx_ptr)
		|| !init_ui_pause_button2(ui_pause, &ui_pause->buttons[1], mlx_ptr)
	)
	{
		destroy_button(&ui_pause->buttons[0], mlx_ptr);
		destroy_button(&ui_pause->buttons[1], mlx_ptr);
		free(ui_pause->buttons);
		ui_pause->buttons = NULL;
		return (false);
	}
	return (true);
}

static bool	init_ui_pause_labels(t_ui *ui_pause, void *mlx_ptr)
{
	t_dimension	dim;

	ui_pause->labels = (t_label *)ft_calloc(ui_pause->nb_labels, \
		sizeof(t_label));
	if (ui_pause->labels == NULL)
		return (false);
	dim.size.x = UI_PAUSE_LBL_W_RATIO * ui_pause->size.x;
	dim.size.y = UI_PAUSE_LBL_H_RATIO * ui_pause->size.y;
	dim.coords.x = ui_pause->pos.x + (ui_pause->size.x / 2 - dim.size.x / 2);
	dim.coords.y = ui_pause->pos.y + ui_pause->size.y / 6;
	if (!init_label(&ui_pause->labels[0], &dim, UI_PAUSE_LBL_TXT_FILE, mlx_ptr))
	{
		free(ui_pause->labels);
		ui_pause->labels = NULL;
		return (false);
	}
	return (true);
}

bool	init_ui_pause(
	t_ui *ui_pause,
	void *mlx_ptr,
	t_list *textures[MAP_NB_IDS]
)
{
	if (ui_pause == NULL || mlx_ptr == NULL)
		return (false);
	ui_pause->texture = (t_image *) textures[8]->content;
	ui_pause->size.x = (int)((float)WIN_WIDTH * UI_PAUSE_W_RATIO);
	ui_pause->size.y = (int)((float)WIN_HEIGHT * UI_PAUSE_H_RATIO);
	ui_pause->pos.x = (WIN_WIDTH - ui_pause->size.x) / 2;
	ui_pause->pos.y = (WIN_HEIGHT - ui_pause->size.y) / 2;
	ui_pause->nb_buttons = UI_PAUSE_NB_BTN;
	if (!init_ui_pause_buttons(ui_pause, mlx_ptr))
	{
		destroy_ui(ui_pause, mlx_ptr);
		return (false);
	}
	ui_pause->nb_labels = UI_PAUSE_NB_LBL;
	if (!init_ui_pause_labels(ui_pause, mlx_ptr))
	{
		destroy_ui(ui_pause, mlx_ptr);
		return (false);
	}
	return (true);
}
