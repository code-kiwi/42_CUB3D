/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_api.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:23:46 by mhotting          #+#    #+#             */
/*   Updated: 2024/06/12 12:42:30 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_API_H
# define MLX_API_H

# include <stdbool.h>

typedef struct s_mlx	t_mlx;
typedef struct s_image	t_image;

struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	*img1;
	t_image	*img2;
};

struct s_image
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
};

// t_mlx functions
bool    t_mlx_init(t_mlx *mlx, size_t win_width, size_t win_height, char *title);
void    t_mlx_destroy(t_mlx *mlx);

// t_image functions
t_image	*t_image_init(void *mlx_ptr, size_t img_width, size_t img_height);
void	t_image_destroy(void *mlx_ptr, t_image *img);

# endif