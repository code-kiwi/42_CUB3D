/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifier_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codekiwi <codekiwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:11:07 by root              #+#    #+#             */
/*   Updated: 2024/07/27 01:34:20 by codekiwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

static void	init_world_identifier(char **identifier)
{
	identifier[IDX_TXTR_N] = ID_TEXTURE_NORTH;
	identifier[IDX_TXTR_S] = ID_TEXTURE_SOUTH;
	identifier[IDX_TXTR_W] = ID_TEXTURE_WEST;
	identifier[IDX_TXTR_E] = ID_TEXTURE_EAST;
	identifier[IDX_TXTR_FLOOR] = ID_TEXTURE_FLOOR;
	identifier[IDX_TXTR_CEIL] = ID_TEXTURE_CEILING;
	identifier[IDX_TXTR_DOOR] = ID_TEXTURE_DOOR;
}

static void	init_ui_identifier(char **identifier)
{
	identifier[IDX_TXTR_SPRITE] = ID_TEXTURE_SPRITE;
	identifier[IDX_TXTR_UIP_BG] = ID_TEXTURE_UI_PAUSE_BG;
	identifier[IDX_TXTR_UIP_LBL] = ID_TEXTURE_UI_PAUSE_LABEL;
	identifier[IDX_TXTR_UIP_B1_ON] = ID_TEXTURE_UI_PAUSE_BTNR_OFF;
	identifier[IDX_TXTR_UIP_B1_OFF] = ID_TEXTURE_UI_PAUSE_BTNR_ON;
	identifier[IDX_TXTR_UIP_B2_ON] = ID_TEXTURE_UI_PAUSE_BTNQ_OFF;
	identifier[IDX_TXTR_UIP_B2_OFF] = ID_TEXTURE_UI_PAUSE_BTNQ_ON;
}

static void	init_enemies_identifier(char **identifier)
{
	identifier[IDX_TXTR_DEMON_WALK] = ID_TEXTURE_DEMON_WALK;
	identifier[IDX_TXTR_DEMON_PAIN] = ID_TEXTURE_DEMON_PAIN;
	identifier[IDX_TXTR_DEMON_ATTACK] = ID_TEXTURE_DEMON_ATTACK;
	identifier[IDX_TXTR_DEMON_DEATH] = ID_TEXTURE_DEMON_DEATH;
	identifier[IDX_TXTR_IMP_WALK] = ID_TEXTURE_IMP_WALK;
	identifier[IDX_TXTR_IMP_PAIN] = ID_TEXTURE_IMP_PAIN;
	identifier[IDX_TXTR_IMP_ATTACK] = ID_TEXTURE_IMP_ATTACK;
	identifier[IDX_TXTR_IMP_DEATH] = ID_TEXTURE_IMP_DEATH;
	identifier[IDX_TXTR_IMP_PROJ_LIVE] = ID_TEXTURE_IMP_PROJ_LIVE;
	identifier[IDX_TXTR_IMP_PROJ_DEATH] = ID_TEXTURE_IMP_PROJ_DEATH;
}

static void	init_weapons_identifier(char **identifier)
{
	identifier[IDX_TXTR_TARGET1] = ID_TEXTURE_TARGET1;
	identifier[IDX_TXTR_W1_HAND] = ID_TEXTURE_W1_HAND;
	identifier[IDX_TXTR_W1_PUNCH] = ID_TEXTURE_W1_PUNCH;
	identifier[IDX_TXTR_W2_PISTOL] = ID_TEXTURE_W2_PISTOL;
	identifier[IDX_TXTR_W3_CHAINGUN] = ID_TEXTURE_W3_CHAINGUN;
}

void	init_identifier(char **identifier)
{
	if (identifier == NULL)
		return ;
	init_world_identifier(identifier);
	init_ui_identifier(identifier);
	init_enemies_identifier(identifier);
	init_weapons_identifier(identifier);
}
