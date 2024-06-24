/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:30:08 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 11:44:52 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

static bool	init_ui_pause(t_ui *ui_pause, void *mlx_ptr)
{
	if (ui_pause == NULL || mlx_ptr == NULL)
		return (false);
	if (!t_image_import_file(&ui_pause->texture, UI_PAUSE_TXT_FILE, mlx_ptr))
		return (false);
	ui_pause->pos.x = UI_PAUSE_POS_X;
	ui_pause->pos.y = UI_PAUSE_POS_Y;
	ui_pause->width = UI_PAUSE_WIDTH;
	ui_pause->height = UI_PAUSE_HEIGHT;
	ui_pause->buttons = NULL;
	return (true);
}

bool	init_all_ui(t_game *game)
{
	if (!init_ui_pause(&game->ui_pause, game->mlx.mlx_ptr))
		return (false);
	return (true);
}
