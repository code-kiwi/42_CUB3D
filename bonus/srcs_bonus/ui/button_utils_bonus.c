/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:22:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/25 14:52:27 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "ui_bonus.h"
#include "mlx_api_bonus.h"

void	destroy_button(t_button *btn, void *mlx_ptr)
{
	if (btn == NULL || mlx_ptr == NULL)
		return ;
	t_image_destroy(mlx_ptr, &btn->texture_off, false);
	t_image_destroy(mlx_ptr, &btn->texture_on, false);
}

void	draw_buttons(t_ui *ui, t_image *img)
{
	size_t		i;
	t_button	*btn;

	if (ui == NULL || img == NULL || ui->buttons == NULL)
		return ;
	i = 0;
	while (i < ui->nb_buttons)
	{
		btn = &ui->buttons[i];
		t_mlx_draw_rect_texture(img, &btn->pos, &btn->size, \
			btn->texture_active);
		i++;
	}
}
