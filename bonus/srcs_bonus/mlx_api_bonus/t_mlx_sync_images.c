/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_sync_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:07:43 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/21 14:07:06 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

void	t_mlx_sync_images(t_mlx *mlx)
{
	unsigned int	*dest_addr;
	unsigned int	*buff_addr;
	int		i;
	int		j; 

	if (mlx == NULL)
		return ;
	buff_addr = (unsigned int *) mlx->img_buff->addr;
	if (mlx->img_buff == mlx->img1)
		dest_addr = (unsigned int *) mlx->img2->addr;
	else
		dest_addr = (unsigned int *) mlx->img1->addr;
	i = 0;
	while (i < mlx->img_buff->height)
	{
		buff_addr += mlx->img_buff->line_len / 4;
		dest_addr += mlx->img_buff->line_len / 4;
		j = 0;
		while (j < mlx->img_buff->width)
		{
			dest_addr[j] = buff_addr[j];
			j++;
		}
		i++;
	}
}