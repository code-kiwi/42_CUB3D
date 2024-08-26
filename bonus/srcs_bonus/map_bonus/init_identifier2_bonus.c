/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifier2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:11:07 by root              #+#    #+#             */
/*   Updated: 2024/08/26 08:14:58 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

void	init_weapons_identifier(char **identifier)
{
	identifier[IDX_TXTR_TARGET1] = ID_TEXTURE_TARGET1;
	identifier[IDX_TXTR_W1_HAND] = ID_TEXTURE_W1_HAND;
	identifier[IDX_TXTR_W1_PUNCH] = ID_TEXTURE_W1_PUNCH;
	identifier[IDX_TXTR_W2_PISTOL] = ID_TEXTURE_W2_PISTOL;
	identifier[IDX_TXTR_W3_CHAINGUN] = ID_TEXTURE_W3_CHAINGUN;
}

void	init_hud_identifier(char **identifier)
{
	identifier[IDX_TXTR_HUD_BG] = ID_TEXTURE_HUD_BG;
	identifier[IDX_TXTR_HUD_HEALTH_LBL] = ID_TEXTURE_HUD_HEALTH_LBL;
	identifier[IDX_TXTR_HUD_WEAPON_LBL] = ID_TEXTURE_HUD_WEAPON_LBL;
}
