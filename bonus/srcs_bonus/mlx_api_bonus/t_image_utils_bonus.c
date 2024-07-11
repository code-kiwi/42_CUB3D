/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:03:23 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/08 14:29:18 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "mlx_api_bonus.h"
#include "mlx.h"
#include "libft.h"
#include "vector_bonus.h"

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
	img->bpp_factor = img->bpp / 8;
	return (img);
}

/**
 * @brief Destroys properly the given t_image instance
 * @param mlx_ptr The mlx pointer associated to the image to destroy
 * @param img The t_image instance to destroy
 * @param free_ptr true if the img ptr has to be freed, else false
*/
void	t_image_destroy(void *mlx_ptr, t_image *img, bool free_ptr)
{
	if (mlx_ptr == NULL || img == NULL || img->ptr == NULL)
		return ;
	mlx_destroy_image(mlx_ptr, img->ptr);
	img->ptr = NULL;
	if (free_ptr)
		free(img);
}

/**
 * @brief import a xpm file into the struct image
 * @param image the results
 * @return false for error, otherwise true
*/
bool	t_image_import_file(
	t_image *image,
	char *filename,
	void *mlx,
	t_mlx_coords *size
)
{
	bool	ret;

	if (image == NULL || mlx == NULL)
		return (false);
	image->ptr = mlx_xpm_file_to_image(mlx, filename,
			&image->width, &image->height);
	if (image->ptr == NULL)
		return (false);
	image->addr = mlx_get_data_addr(image->ptr, &image->bpp,
			&image->line_len, &image->endian);
	if (image->addr == NULL)
	{
		mlx_destroy_image(mlx, image->ptr);
		image->ptr = NULL;
		return (false);
	}
	image->bpp_factor = image->bpp / 8;
	if (size != NULL && (image->width != size->x || image->height != size->y))
	{
		ret = t_image_resize(mlx, image, size);
		if (!ret)
			mlx_destroy_image(mlx, image->ptr);
		return (ret);
	}
	return (true);
}
