/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_gameover_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:23:09 by mhotting          #+#    #+#             */
/*   Updated: 2024/09/05 01:31:10 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "libft.h"

static bool	init_ui_gameover_btn(
	t_ui *ui_gameover,
	t_button *btn,
	void *mlx_ptr,
	t_image textures[UI_NB_TEXTURES]
)
{
	btn->size.x = UI_GAMEOVER_BTN_W_RATIO * ui_gameover->size.x;
	btn->size.y = UI_GAMEOVER_BTN_H_RATIO * ui_gameover->size.y;
	btn->pos.x = ui_gameover->pos.x \
		+ (ui_gameover->size.x / 2 - btn->size.x / 2);
	btn->pos.y = ui_gameover->pos.y + 3 * ui_gameover->size.y / 5;
	btn->texture_off = &textures[UI_TXTR_IDX_GAMEOVER_BTN_QUIT_OFF];
	btn->texture_on = &textures[UI_TXTR_IDX_GAMEOVER_BTN_QUIT_ON];
	if (
		!t_image_resize(mlx_ptr, btn->texture_off, &btn->size)
		|| !t_image_resize(mlx_ptr, btn->texture_on, &btn->size)
	)
		return (false);
	btn->texture_active = btn->texture_off;
	btn->callback = (void (*)(void *)) t_game_destroy_and_exit;
	return (true);
}

static bool	init_ui_gameover_button(
	t_ui *ui_gameover,
	void *mlx,
	t_image textures[UI_NB_TEXTURES]
)
{
	ui_gameover->buttons = (t_button *)ft_calloc(ui_gameover->nb_buttons, \
		sizeof(t_button));
	if (ui_gameover->buttons == NULL)
		return (false);
	if (!init_ui_gameover_btn(ui_gameover, &ui_gameover->buttons[0], mlx, \
		textures))
	{
		free(ui_gameover->buttons);
		ui_gameover->buttons = NULL;
		return (false);
	}
	return (true);
}

static bool	init_ui_gameover_label(
	t_ui *ui_gameover,
	void *mlx_ptr,
	t_image textures[UI_NB_TEXTURES]
)
{
	t_dimension	dim;

	ui_gameover->labels = (t_label *)ft_calloc(ui_gameover->nb_labels, \
		sizeof(t_label));
	if (ui_gameover->labels == NULL)
		return (false);
	dim.size.x = UI_GAMEOVER_LBL_W_RATIO * ui_gameover->size.x;
	dim.size.y = UI_GAMEOVER_LBL_H_RATIO * ui_gameover->size.y;
	dim.coords.x = ui_gameover->pos.x + (ui_gameover->size.x / 2 \
		- dim.size.x / 2);
	dim.coords.y = ui_gameover->pos.y + ui_gameover->size.y / 6;
	if (!init_label(&ui_gameover->labels[0], &dim, \
		&textures[UI_TXTR_IDX_GAMEOVER_LABEL], mlx_ptr))
	{
		free(ui_gameover->labels);
		ui_gameover->labels = NULL;
		return (false);
	}
	return (true);
}

bool	init_ui_gameover(
	t_ui *ui_gameover,
	void *mlx_ptr,
	t_image textures[UI_NB_TEXTURES]
)
{
	if (ui_gameover == NULL || mlx_ptr == NULL)
		return (false);
	ui_gameover->texture = &textures[UI_TXTR_IDX_GAMEOVER_BG];
	ui_gameover->size.x = (int)((float)WIN_WIDTH * UI_GAMEOVER_W_RATIO);
	ui_gameover->size.y = (int)((float)WIN_HEIGHT * UI_GAMEOVER_H_RATIO);
	ui_gameover->pos.x = (WIN_WIDTH - ui_gameover->size.x) / 2;
	ui_gameover->pos.y = (WIN_HEIGHT - ui_gameover->size.y) / 2;
	ui_gameover->nb_buttons = UI_GAMEOVER_NB_BTN;
	if (!init_ui_gameover_button(ui_gameover, mlx_ptr, textures))
	{
		destroy_ui(ui_gameover, mlx_ptr);
		return (false);
	}
	ui_gameover->nb_labels = UI_GAMEOVER_NB_LBL;
	if (!init_ui_gameover_label(ui_gameover, mlx_ptr, textures))
	{
		destroy_ui(ui_gameover, mlx_ptr);
		return (false);
	}
	return (true);
}
