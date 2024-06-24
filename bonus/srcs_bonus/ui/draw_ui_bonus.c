/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:04:30 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 13:37:28 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui_bonus.h"

void	draw_ui(t_ui *ui, t_image *img)
{
	if (ui == NULL || img == NULL)
		return ;
	t_mlx_draw_rect_texture(img, &ui->pos, &ui->size, &ui->texture);
}
