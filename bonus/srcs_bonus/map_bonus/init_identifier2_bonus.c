/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifier2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:11:07 by root              #+#    #+#             */
/*   Updated: 2024/08/27 18:26:48 by mhotting         ###   ########.fr       */
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
	identifier[IDX_TXTR_W4_BF_GUN] = ID_TEXTURE_W4_BF_GUN;
	identifier[IDX_TXTR_W5_CHAINSAW] = ID_TEXTURE_W5_CHAINSAW;
	identifier[IDX_TXTR_W6_PLASMA] = ID_TEXTURE_W6_PLASMA;
	identifier[IDX_TXTR_W7_SHOTGUN] = ID_TEXTURE_W7_SHOTGUN;
	identifier[IDX_TXTR_W8_ROCKET] = ID_TEXTURE_W8_ROCKET;
}

void	init_hud_identifier(char **identifier)
{
	identifier[IDX_TXTR_HUD_BG] = ID_TEXTURE_HUD_BG;
	identifier[IDX_TXTR_HUD_HEALTH_LBL] = ID_TEXTURE_HUD_HEALTH_LBL;
	identifier[IDX_TXTR_HUD_WEAPON_LBL] = ID_TEXTURE_HUD_WEAPON_LBL;
}
