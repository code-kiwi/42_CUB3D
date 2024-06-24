/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:22:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 15:01:54 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "ui_bonus.h"
#include "mlx_api_bonus.h"

bool	init_label(
	t_label *label,
	t_dimension	*dim,
	char *filename,
	void *mlx_ptr
)
{
	if (label == NULL || dim == NULL || filename == NULL || mlx_ptr == NULL)
		return (false);
	if (!t_image_import_file(&label->texture, filename, mlx_ptr))
		return (false);
	label->pos.x = dim->coords.x;
	label->pos.y = dim->coords.y;
	label->size.x = dim->size.x;
	label->size.y = dim->size.y;
	return (true);
}

void	destroy_label(t_label *label, void *mlx_ptr)
{
	if (label == NULL || mlx_ptr == NULL)
		return ;
	t_image_destroy(mlx_ptr, &label->texture, false);
}

void	draw_labels(t_ui *ui, t_image *img)
{
	size_t	i;
	t_label	*lbl;

	if (ui == NULL || img == NULL || ui->labels == NULL)
		return ;
	i = 0;
	while (i < ui->nb_labels)
	{
		lbl = &ui->labels[i];
		t_mlx_draw_rect_texture(img, &lbl->pos, &lbl->size, &lbl->texture);
		i++;
	}
}
