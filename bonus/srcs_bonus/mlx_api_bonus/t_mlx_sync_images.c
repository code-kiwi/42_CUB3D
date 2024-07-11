/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_sync_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:07:43 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/24 09:10:44 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"

static void	t_mlx_sync_images_copy(
	unsigned int *dest,
	unsigned int *src,
	int width
)
{
	int	i;

	i = 0;
	while (i < width)
	{
		dest[i] = src[i];
		i++;
	}
}

void	t_mlx_sync_images(t_mlx *mlx)
{
	char	*dest_addr;
	char	*buff_addr;
	int		i;

	if (mlx == NULL)
		return ;
	buff_addr = mlx->img_buff->addr;
	if (mlx->img_buff == mlx->img1)
		dest_addr = mlx->img2->addr;
	else
		dest_addr = mlx->img1->addr;
	i = 0;
	while (i < mlx->img_buff->height)
	{
		buff_addr += mlx->img_buff->line_len;
		dest_addr += mlx->img_buff->line_len;
		t_mlx_sync_images_copy((unsigned int *)dest_addr, \
			(unsigned int *)buff_addr, mlx->img_buff->width);
		i++;
	}
}
