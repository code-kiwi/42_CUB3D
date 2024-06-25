/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/25 21:16:31 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_bonus.h"

int	mouse_press_handler(int button, int x, int y, t_game *data)
{
    if (button || data)
        printf("Button in\n");
    printf("Button: %d pressed, x: %d, y: %d, pause: %d\n", button, x, y, data->pause);
    return (1);
}