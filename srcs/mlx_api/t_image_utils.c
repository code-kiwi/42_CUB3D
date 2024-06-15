/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:03:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/15 12:19:27 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx_api.h"
#include "mlx.h"
#include "libft.h"

/**
 * @brief Allocates and initializes a t_image_instance using the mlx
 * @param mlx_ptr A pointer to an mlx instance, required for creating the mlx
 * image
 * @param img_width The image width
 * @param img_height The image height
 * @return A pointer to the created image, NULL in case of ERROR
*/
t_image	*t_image_init(void *mlx_ptr, int img_width, int img_height)
{
	t_image	*img;

	if (mlx_ptr == NULL || img_width < 0 || img_height < 0)
		return (NULL);
	img = (t_image *) ft_calloc(1, sizeof(t_image));
	if (img == NULL)
		return (NULL);
	img->ptr = mlx_new_image(mlx_ptr, img_width, img_height);
	if (img->ptr == NULL)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(\
			img->ptr, &img->bpp, &img->line_len, &img->endian);
	if (img->addr == NULL)
	{
		mlx_destroy_image(mlx_ptr, img->ptr);
		free(img);
		return (NULL);
	}
	img->width = img_width;
	img->height = img_height;
	return (img);
}

/**
 * @brief Destroys properly the given t_image instance
 * @param mlx_ptr The mlx pointer associated to the image to destroy
 * @param img The t_image instance to destroy
*/
void	t_image_destroy(void *mlx_ptr, t_image *img)
{
	if (mlx_ptr == NULL || img == NULL || img->ptr == NULL)
		return ;
	mlx_destroy_image(mlx_ptr, img->ptr);
	free(img);
}

/**
 * @brief Clears the given t_image instance
 * 
 * Clearing means that the image pixels will all be black
 * @param img The image to clear
*/
void	t_image_clear(t_image *img)
{
	t_mlx_coords	coords;

	if (img == NULL)
		return ;
	coords.y = 0;
	while (coords.y < img->height)
	{
		coords.x = 0;
		while (coords.x < img->width)
		{
			t_mlx_draw_pixel(img, &coords, 0);
			coords.x++;
		}
		coords.y++;
	}
}
