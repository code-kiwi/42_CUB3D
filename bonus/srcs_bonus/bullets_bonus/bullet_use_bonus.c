/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet_use_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:09:39 by root              #+#    #+#             */
/*   Updated: 2024/07/17 11:41:42 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "entities_bonus.h"
#include "bullets_bonus.h"

void	bullet_use(t_game *game, t_bullet *bullet)
{
	if (game == NULL || game->entities == NULL)
		return ;
	ft_lst_remove_if(&game->sprites, bullet->sprite, equal, free);
	ft_lst_remove_if(&game->bullets, bullet, equal, free);
}
