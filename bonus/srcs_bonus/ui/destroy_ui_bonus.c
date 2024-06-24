/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ui_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:36:13 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 11:47:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"

static void	destroy_ui(t_ui *ui, void *mlx_ptr)
{
	if (ui == NULL || mlx_ptr == NULL)
		return ;
	t_image_destroy(mlx_ptr, &ui->texture, false);
}

void	destroy_all_ui(t_game *game)
{
	if (game == NULL)
		return ;
	destroy_ui(&game->ui_pause, game->mlx.mlx_ptr);
}
