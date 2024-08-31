/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:48:08 by brappo            #+#    #+#             */
/*   Updated: 2024/09/01 01:09:05 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "door_bonus.h"

static t_image	*get_texture(t_animation anim[MAP_NB_IDS], t_ray *ray)
{
	if (ray->is_door)
		return (anim[IDX_TXTR_DOOR].textures->content);
	if (ray->is_vertical)
	{
		if (ray->slope.x > 0)
			return (anim[IDX_TXTR_E].textures->content);
		else
			return (anim[IDX_TXTR_W].textures->content);
	}
	else
	{
		if (ray->slope.y > 0)
			return (anim[IDX_TXTR_N].textures->content);
		else
			return (anim[IDX_TXTR_S].textures->content);
	}
}

static int	pixel_column_on_texture(t_ray *ray, int texture_width)
{
	int		column;
	float	texture_relative_position;
	double	temp;

	if (ray->is_vertical)
		texture_relative_position = modf(ray->intersection.y, &temp);
	else
		texture_relative_position = modf(ray->intersection.x, &temp);
	if (ray->is_door)
		texture_relative_position = ray->door->transition \
			- texture_relative_position;
	column = floorf(texture_relative_position * texture_width);
	return (column);
}

static float	range(float value)
{
	if (value < 0)
		return (0);
	if (value > WIN_HEIGHT)
		return (WIN_HEIGHT);
	return (value);
}

static void	draw_wall_column(size_t column_index, t_ray *ray, t_game *game)
{
	t_column	column;
	t_image		*texture;
	int			offset;

	offset = game->player.orientation.y;
	column.coords.x = column_index;
	column.perceived_height = WIN_HEIGHT
		/ (ray->length * ray->cos_angle_from_orientation);
	column.start = floorf((WIN_HEIGHT - column.perceived_height) / 2) + offset;
	column.end = range((WIN_HEIGHT + column.perceived_height) / 2 + offset);
	column.coords.y = range(column.start);
	column.texture_start = column.coords.y - column.start;
	texture = get_texture(game->anim, ray);
	column.texture_column = pixel_column_on_texture(ray, texture->width);
	column.real_ceiling_start = WIN_HEIGHT - (column.coords.y - offset);
	column.real_ground_start = column.end - offset;
	draw_ceiling(&column, column.coords.y - 1, game, ray);
	draw_texture_column(game->mlx.img_buff, &column, texture, ray->length);
	draw_ground(&column, column.coords.y, game, ray);
}

void	draw_walls_part(t_game *game, size_t start, size_t end)
{
	size_t	i;

	i = start;
	while (i < end)
	{
		draw_wall_column(i, &game->rays[i], game);
		i++;
	}
}

typedef struct s_test
{
	t_game *game;
	size_t	start;
	size_t	end;
} t_test;

#include <stdio.h>
void	*routine(void *param)
{
	t_test	*test;

	test = (t_test *) param;
	draw_walls_part(test->game, test->start, test->end);
	return (NULL);
}

#include <pthread.h>
void	draw_walls(t_game *game)
{
	pthread_t	threads[4];
	t_test		test_array[4];

	test_array[0].game = game;
	test_array[0].start = 0;
	test_array[0].end = WIN_WIDTH / 4;
	test_array[1].game = game;
	test_array[1].start = test_array[0].end;
	test_array[1].end = WIN_WIDTH / 2;
	test_array[2].game = game;
	test_array[2].start = test_array[1].end;
	test_array[2].end = 3 * WIN_WIDTH / 4;
	test_array[3].game = game;
	test_array[3].start = test_array[2].end;
	test_array[3].end = WIN_WIDTH;
	if (pthread_create(&threads[0], NULL, routine, &test_array[0]) != 0)
		printf("ERROR\n");
	if (pthread_create(&threads[1], NULL, routine, &test_array[1]) != 0)
		printf("ERROR\n");
	if (pthread_create(&threads[2], NULL, routine, &test_array[2]) != 0)
		printf("ERROR\n");
	if (pthread_create(&threads[4], NULL, routine, &test_array[3]) != 0)
		printf("ERROR\n");
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	pthread_join(threads[3], NULL);
}
