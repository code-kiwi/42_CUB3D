/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:36:13 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/25 14:50:23 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

void	destroy_ui(t_ui *ui, void *mlx_ptr)
{
	size_t	i;

	if (ui == NULL || mlx_ptr == NULL)
		return ;
	t_image_destroy(mlx_ptr, &ui->texture, false);
	if (ui->buttons != NULL)
	{
		i = 0;
		while (i < ui->nb_buttons)
			destroy_button(&ui->buttons[i++], mlx_ptr);
		free(ui->buttons);
	}
	if (ui->labels != NULL)
	{
		i = 0;
		while (i < ui->nb_labels)
			destroy_label(&ui->labels[i++], mlx_ptr);
		free(ui->labels);
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
		return (false);
	if (!init_ui_pause(&game->ui_pause, game->mlx.mlx_ptr))
		return (false);
	return (true);
}

void	draw_ui(t_ui *ui, t_image *img)
{
	if (ui == NULL || img == NULL)
		return ;
	t_mlx_draw_rect_texture(img, &ui->pos, &ui->size, &ui->texture);
	draw_labels(ui, img);
	draw_buttons(ui, img);
}
