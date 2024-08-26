/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:36:13 by mhotting          #+#    #+#             */
/*   Updated: 2024/08/26 15:43:36 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

void	destroy_ui(t_ui *ui, void *mlx_ptr)
{
	if (ui == NULL || mlx_ptr == NULL)
		return ;
	if (ui->buttons != NULL)
	{
		free(ui->buttons);
		ui->buttons = NULL;
	}
	if (ui->labels != NULL)
	{
		free(ui->labels);
		ui->labels = NULL;
	}
}

void	destroy_all_ui(t_game *game)
{
	if (game == NULL)
		return ;
	destroy_ui(&game->ui_pause, game->mlx.mlx_ptr);
}

bool	init_all_ui(t_game *game)
{
	if (game == NULL)
		return (error_print(ERR_UI_CREATION), false);
	if (
		!init_ui_pause(&game->ui_pause, game->mlx.mlx_ptr, game->anim)
		|| !init_ui_gameover(&game->ui_game_over, game->mlx.mlx_ptr, game->anim)
	)
		return (error_print(ERR_UI_CREATION), false);
	return (true);
}

void	draw_ui(t_ui *ui, t_image *img)
{
	if (ui == NULL || img == NULL)
		return ;
	t_mlx_draw_rect_texture(img, &ui->pos, &ui->size, ui->texture);
	draw_labels(ui, img);
	draw_buttons(ui, img);
}

void	disable_buttons_ui(t_ui *ui)
{
	size_t		i;

	if (ui == NULL)
		return ;
	i = 0;
	while (i < ui->nb_buttons)
	{
		ui->buttons[i].texture_active = ui->buttons[i].texture_off;
		i++;
	}
}
