/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_handler_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:15 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/25 20:46:58 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_bonus.h"

int	mouse_move_handler(int x, int y, t_game *data)
{
    if (x || y || data)
        printf("Mouse handler in\n");
    printf("Mouse handler: x: %d, y: %d, pause: %d\n", x, y, data->pause);
    return (1);
}