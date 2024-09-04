/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_height_offset_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brappo <brappo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:19:07 by brappo            #+#    #+#             */
/*   Updated: 2024/09/04 07:45:16 by brappo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_player_height_offset(float perceived_height, int camera_y_diff)
{
	return (camera_y_diff - camera_y_diff * perceived_height / WIN_HEIGHT);
}