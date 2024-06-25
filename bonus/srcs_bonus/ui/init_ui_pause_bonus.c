/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_pause_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:27:12 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/25 14:51:36 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


#include <stdlib.h>
#include <stdbool.h>

#include "cub3d_bonus.h"
#include "ui_bonus.h"
#include "libft.h"

void	cb(t_game *game)
{
	if (game == NULL)
		return ;
	printf("In callbacks func...%d\n", game->pause);
}

static bool	init_ui_pause_button1(t_ui *ui_pause, t_button *btn, void *mlx_ptr)
{
	btn->pos.x = UI_PAUSE_BTN1_POS_X + ui_pause->pos.x;
	btn->pos.y = UI_PAUSE_BTN1_POS_Y + ui_pause->pos.y;
	btn->size.x = UI_PAUSE_BTN1_WIDTH;
	btn->size.y = UI_PAUSE_BTN1_HEIGHT;
	if (!t_image_import_file(&btn->texture_off, \
		UI_PAUSE_BTN1_OFF_FILE, mlx_ptr))
		return (false);
	if (!t_image_import_file(&btn->texture_on, UI_PAUSE_BTN1_ON_FILE, mlx_ptr))
	{
		t_image_destroy(mlx_ptr, &btn->texture_off, false);
		return (false);
	}
	btn->texture_active = &btn->texture_off;
	btn->callback = (void (*)(void *)) cb;
	return (true);
}

static bool	init_ui_pause_buttons(t_ui *ui_pause, void *mlx_ptr)
{
	ui_pause->buttons = (t_button *)ft_calloc(ui_pause->nb_buttons, \
		sizeof(t_button));
	if (ui_pause->buttons == NULL)
		return (false);
	if (!init_ui_pause_button1(ui_pause, &ui_pause->buttons[0], mlx_ptr))
	{
		destroy_button(&ui_pause->buttons[0], mlx_ptr);
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
	dim.coords.x = UI_PAUSE_LBL_POS_X + ui_pause->pos.x;
	dim.coords.y = UI_PAUSE_LBL_POS_Y + ui_pause->pos.y;
	dim.size.x = UI_PAUSE_LBL_WIDTH;
	dim.size.y = UI_PAUSE_LBL_HEIGHT;
	if (!init_label(&ui_pause->labels[0], &dim, UI_PAUSE_LBL_TXT_FILE, mlx_ptr))
	{
		free(ui_pause->labels);
		ui_pause->labels = NULL;
		return (false);
	}
	return (true);
}

bool	init_ui_pause(t_ui *ui_pause, void *mlx_ptr)
{
	if (ui_pause == NULL || mlx_ptr == NULL)
		return (false);
	if (!t_image_import_file(&ui_pause->texture, UI_PAUSE_TXT_FILE, mlx_ptr))
		return (false);
	ui_pause->size.x = UI_PAUSE_WIDTH;
	ui_pause->size.y = UI_PAUSE_HEIGHT;
	ui_pause->pos.x = (WIN_WIDTH - UI_PAUSE_WIDTH) / 2;
	ui_pause->pos.y = (WIN_HEIGHT - UI_PAUSE_HEIGHT) / 2;
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
