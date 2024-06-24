/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:52:44 by brappo            #+#    #+#             */
/*   Updated: 2024/06/24 13:22:32 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_api_bonus.h"
#include "sprite_bonus.h"
#include "animation_bonus.h"
#include "cub3d_bonus.h"

static void	copy_image(t_image *dest, t_image *src, t_mlx_coords *src_coords)
{
	char			*color;
	t_mlx_coords	dest_coords;

	dest_coords.y = 0;
	while (dest_coords.y < TEXTURE_SIZE)
	{
		dest_coords.x = 0;
		while (dest_coords.x < TEXTURE_SIZE)
		{
			color = t_mlx_get_pixel(src, src_coords->x + dest_coords.x,
					src_coords->y + dest_coords.y);
			t_mlx_draw_pixel(dest, &dest_coords, *(unsigned int *)color);
			dest_coords.x++;
		}
		dest_coords.y++;
	}
}

static bool	add_anim_sprite(t_list **anim, t_image *texture,
	t_mlx_coords *coords, void *mlx_ptr)
{
	t_image	*image;
	t_list	*new_node;

	image = t_image_init(mlx_ptr, TEXTURE_SIZE, TEXTURE_SIZE);
	if (image == NULL)
		return (false);
	copy_image(image, texture, coords);
	new_node = ft_lstnew(image);
	if (new_node == NULL)
	{
		t_image_destroy(mlx_ptr, image);
		return (false);
	}
	ft_lstadd_front(anim, new_node);
	return (true);
}

t_list	*create_animation(t_image *texture, void *mlx_ptr)
{
	t_list			*anim;
	t_mlx_coords	coords;

	if (texture->width % TEXTURE_SIZE != 0
		|| texture->height % TEXTURE_SIZE != 0)
		return (error_print(ERR_TEXTURE_SIZE), NULL);
	coords.y = 0;
	anim = NULL;
	while (coords.y < texture->height)
	{
		coords.x = 0;
		while (coords.x < texture->width)
		{
			if (!add_anim_sprite(&anim, texture, &coords, mlx_ptr))
			{
				destroy_animation(anim, mlx_ptr, false);
				return (NULL);
			}
			coords.x += TEXTURE_SIZE;
		}
		coords.y += TEXTURE_SIZE;
	}
	if (anim != NULL)
		ft_lstlast(anim)->next = anim;
	return (anim);
}
