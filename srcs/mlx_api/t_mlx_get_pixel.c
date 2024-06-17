/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_mlx_get_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:38:25 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/17 11:47:03 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_api.h"
#include "mlx.h"

/**
 * @return The pixel adresses
 * @param x The column of the pixel
 * @param y The row of the pixel
 */
char	*t_mlx_get_pixel(t_image *image, size_t x, size_t y)
{
	return (image->addr + x * image->line_len + y * (image->bpp / 8));
}
