/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:25:35 by brappo            #+#    #+#             */
/*   Updated: 2024/06/21 12:20:06 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "cub3d_bonus.h"
#include "mlx.h"

static void	update_look(t_player *player, float delta_time, int turn_direction)
{
	if (turn_direction < 0)
		player->orientation += player->rotation_speed * delta_time;
	else if (turn_direction > 0)
		player->orientation -= player->rotation_speed * delta_time;
}

static void	update_position(t_player *player, t_map *map, float delta_time)
{
	float		new_angle;
	t_vector	save_position;
	size_t		index;

	index = 0;
	while (index < 4)
	{
		if (player->is_walking[index] != false
			&& player->is_walking[(index + 2) % 4] == false)
		{
			save_position = player->position;
			new_angle = player->orientation + index * PI / 2;
			player->position.x += cos(new_angle) * player->move_speed[index] \
				* delta_time;
			player->position.y -= sin(new_angle) * player->move_speed[index] \
				* delta_time;
			if (is_wall(&player->position, map))
				player->position = save_position;
		}
		index++;
	}
}

void	get_mouse_pos(t_mlx_coords *mouse, t_mlx *mlx)
{
	int	mouse_x;
	int	mouse_y;


	mlx_mouse_get_pos(mlx->mlx_ptr, mlx->mlx_win, &mouse_x, &mouse_y);
	mouse->x = mouse_x;
	mouse->y = mouse_y;
}

void	update_player(t_game *game, float delta_time)
{
	int				turn_direction;
	t_mlx_coords	mouse;

	get_mouse_pos(&mouse, &game->mlx);
	turn_direction = mouse.x - game->mouse.x;
	update_look(&game->player, delta_time, turn_direction);
	update_position(&game->player, &game->map, delta_time);
	if (mouse.x <= 0 + MOUSE_RANGE || mouse.x >= WIN_WIDTH - MOUSE_RANGE)
	{
		mlx_mouse_move(game->mlx.mlx_ptr, game->mlx.mlx_win, WIN_WIDTH / 2,
			WIN_HEIGHT / 2);
		game->mouse.x = WIN_WIDTH / 2;
		game->mouse.y = WIN_HEIGHT / 2;
	}
	else
	{
		game->mouse.x = mouse.x;
		game->mouse.y = mouse.y;
	}
}
