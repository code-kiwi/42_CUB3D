/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 18:53:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/16 10:01:02 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"


#include <stdio.h>
void	print_radar(t_radar *radar)
{
	int	i;
	int	j;

	i = 0;
	while (i < radar->tiles_size)
	{
		j = 0;
		while (j < radar->tiles_size)
		{
			printf("%c", radar->tiles[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	draw_radar(t_game *game, t_radar *radar, t_mlx *mlx)
{
	if (game == NULL || radar == NULL || mlx == NULL)
		return ;
	update_tiles(&game->map, radar, &game->player);
	print_radar(radar);
	t_mlx_draw_disk(radar->img, &radar->center, radar->radius, radar->color_bg);
	t_mlx_draw_disk(radar->img, &radar->center, 5, 0x0000FF);
	t_mlx_apply_image(radar->img, mlx->img_buff, &radar->coords);
}