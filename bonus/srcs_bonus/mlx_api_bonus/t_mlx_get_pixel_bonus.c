/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_get_pixel_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/19 11:08:43 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api_bonus.h"
#include "mlx.h"

/**
 * @return The pixel adresses
 * @param x The column of the pixel
 * @param y The row of the pixel
 */
char	*t_mlx_get_pixel(t_image *image, size_t x, size_t y)
{
	return (image->addr + y * image->line_len + x * (image->bpp / 8));
}
