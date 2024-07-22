/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:12:18 by mhotting          #+#    #+#             */
/*   Updated: 2024/07/22 12:14:41 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "cub3d_bonus.h"


#include <stdio.h>
bool	init_weapons(t_game *game)
{
	if (game == NULL)
		return (error_print(ERR_WEAPONS_CREATION), false);
	printf("Creates Weapons...\n");
	return (true);
}
