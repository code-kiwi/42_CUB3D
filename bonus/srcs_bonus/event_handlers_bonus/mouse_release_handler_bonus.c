/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_release_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:35:11 by codekiwi          #+#    #+#             */
/*   Updated: 2024/06/25 20:54:54 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "cub3d_bonus.h"

int	mouse_release_handler(int button, t_game *data)
{
    if (button || data)
        printf("Button released\n");
    printf("Button: %d released\n", button);
    return (1);
}