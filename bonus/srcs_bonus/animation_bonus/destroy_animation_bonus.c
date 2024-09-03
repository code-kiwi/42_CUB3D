/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_animation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:32:35 by brappo            #+#    #+#             */
/*   Updated: 2024/08/27 13:41:11 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_api_bonus.h"

void	destroy_animation_textures(t_list *textures, void *mlx_ptr)
{
	t_list	*previous;

	while (textures)
	{
		t_image_destroy(mlx_ptr, textures->content, true);
		previous = textures;
		textures = textures->next;
		free(previous);
	}
}
