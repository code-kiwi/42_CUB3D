/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:22:52 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 14:53:05 by mhotting         ###   ########.fr       */
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
