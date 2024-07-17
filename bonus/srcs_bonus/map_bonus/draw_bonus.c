/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:43:13 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/17 19:55:55 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx_api_bonus.h"


#include <stdio.h>

void	draw_map(t_map *map, t_game *game)
{
	if (map == NULL || game == NULL)
		return ;
	t_mlx_coords pos = {100, 100}, size = {200, 200};
	t_mlx_draw_rectangle(game->mlx.img_buff, &pos, &size, 0xFF0000);
	printf("DRAW MAP\n");
	return ;
}
