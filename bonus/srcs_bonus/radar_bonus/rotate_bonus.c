/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:11:05 by codekiwi          #+#    #+#             */
/*   Updated: 2024/07/19 00:28:23 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"


#include <stdio.h>

static void	draw_radar_rotate_process(
	t_image *curr,
	t_image *res,
	int img_size,
	float orientation
)
{
	uint32_t	*curr_addr;
	uint32_t	*res_addr;
	int			i;
	int			j;
	int			it;
	int			jt;
	float		i_res;
	float		j_res;

	curr_addr = (uint32_t *) curr->addr;
	res_addr = (uint32_t *) res->addr;
	i = 0;
	while (i < img_size)
	{
		j = 0;
		while (j < img_size)
		{
			if (*(curr_addr + i * img_size + j) == RAD_COL_TRANSPARENT)
			{
				j++;
				continue ;
			}
			it = i - img_size / 2;
			jt = j - img_size / 2;
			i_res = (float) it * cos(-orientation) - (float) jt * sin(-orientation);
			j_res = (float) it * sin(-orientation) + (float) jt * cos(-orientation);
			// printf("it, jt: %d - %d\n", it, jt);
			// printf("i_res, j_res: %f - %f\n", i_res, j_res);
			// printf("orientation: %f\n", orientation);
			*(res_addr + ((int)i_res + img_size / 2) * img_size + ((int)j_res + img_size / 2)) = *(curr_addr + i * img_size + j);
			j++;
		}
		i++;
	}
	// exit(0);
}
void	draw_radar_rotate(t_radar *radar)
{
	t_image	*curr;
	t_image	*res;

	curr = radar->img;
	res = radar->img2;
	draw_radar_rotate_process(curr, res, radar->radius * 2, radar->orientation);

	// t_mlx_coords coords = {0, 0}, size = {2 * radar->radius, 2 * radar->radius};
	// t_mlx_draw_rectangle(res, &coords, &size, 0xFF0000);
	radar->img = res;
	radar->img2 = curr;
	return ;
}