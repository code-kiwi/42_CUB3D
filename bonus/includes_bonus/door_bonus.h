/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:42:39 by root              #+#    #+#             */
/*   Updated: 2024/07/15 13:59:23 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_BONUS_H
# define DOOR_BONUS_H

# include "cub3d_bonus.h"

# define DOOR_SPEED						1
# define DOOR_TIME_TO_CLOSE				3

enum e_door_state
{
	CLOSED,
	OPENING,
	CLOSING,
	OPENED
};

struct	s_door
{
	float			transition;
	t_mlx_coords	position;
	t_door_state	state;
	float			time_since_opened;
};

void		open_looked_door(t_ray *look_ray, t_map *map);
void		update_doors(t_game *game, float delta_time);
t_door		*find_door_at_position(t_mlx_coords *position, t_game *game);
bool		init_doors(t_game *game);

#endif
