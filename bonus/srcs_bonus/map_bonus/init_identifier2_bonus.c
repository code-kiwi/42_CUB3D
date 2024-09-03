/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_identifier2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:11:07 by root              #+#    #+#             */
/*   Updated: 2024/09/03 09:33:01 by mhotting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"

static void	init_weapons_identifier(char **identifier)
{
	identifier[IDX_TXTR_TARGET1] = ID_TEXTURE_TARGET1;
	identifier[IDX_TXTR_W1_HAND] = ID_TEXTURE_W1_HAND;
	identifier[IDX_TXTR_W1_PUNCH] = ID_TEXTURE_W1_PUNCH;
	identifier[IDX_TXTR_W2_PISTOL] = ID_TEXTURE_W2_PISTOL;
	identifier[IDX_TXTR_W3_CHAINGUN] = ID_TEXTURE_W3_CHAINGUN;
	identifier[IDX_TXTR_W4_BF_GUN] = ID_TEXTURE_W4_BF_GUN;
	identifier[IDX_TXTR_W5_PLASMA] = ID_TEXTURE_W5_PLASMA;
	identifier[IDX_TXTR_W6_SHOTGUN] = ID_TEXTURE_W6_SHOTGUN;
	identifier[IDX_TXTR_W7_ROCKET] = ID_TEXTURE_W7_ROCKET;
	identifier[IDX_TXTR_W8_CHAINSAW] = ID_TEXTURE_W8_CHAINSAW;
	identifier[IDX_TXTR_W_BUL_BASIC_LIVE] = ID_TEXTURE_W_BUL_BASIC_LIVE;
	identifier[IDX_TXTR_W_BUL_BASIC_DEATH] = ID_TEXTURE_W_BUL_BASIC_DEATH;
	identifier[IDX_TXTR_W_BUL_ROCKET_LIVE] = ID_TEXTURE_W_BUL_ROCKET_LIVE;
	identifier[IDX_TXTR_W_BUL_ROCKET_DEATH] = ID_TEXTURE_W_BUL_ROCKET_DEATH;
	identifier[IDX_TXTR_W_BUL_PLASMA_LIVE] = ID_TEXTURE_W_BUL_PLASMA_LIVE;
	identifier[IDX_TXTR_W_BUL_PLASMA_DEATH] = ID_TEXTURE_W_BUL_PLASMA_DEATH;
}

static void	init_hud_identifier(char **identifier)
{
	identifier[IDX_TXTR_HUD_BG] = ID_TEXTURE_HUD_BG;
	identifier[IDX_TXTR_HUD_HEALTH_LBL] = ID_TEXTURE_HUD_HEALTH_LBL;
	identifier[IDX_TXTR_HUD_WEAPON_LBL] = ID_TEXTURE_HUD_WEAPON_LBL;
}

static void	init_ui_identifier1(char **identifier)
{
	identifier[IDX_TXTR_UIP_BG] = ID_TEXTURE_UI_PAUSE_BG;
	identifier[IDX_TXTR_UIP_LBL] = ID_TEXTURE_UI_PAUSE_LABEL;
	identifier[IDX_TXTR_UIP_B1_ON] = ID_TEXTURE_UI_PAUSE_BTNR_OFF;
	identifier[IDX_TXTR_UIP_B1_OFF] = ID_TEXTURE_UI_PAUSE_BTNR_ON;
	identifier[IDX_TXTR_UIP_B2_ON] = ID_TEXTURE_UI_PAUSE_BTNQ_OFF;
	identifier[IDX_TXTR_UIP_B2_OFF] = ID_TEXTURE_UI_PAUSE_BTNQ_ON;
	identifier[IDX_TXTR_UI_GAMEOVER_BG] = ID_TEXTURE_UI_GAMEOVER_BG;
	identifier[IDX_TXTR_UI_GAMEOVER_LABEL] = ID_TEXTURE_UI_GAMEOVER_LABEL;
	identifier[IDX_TXTR_UI_GAMEOVER_BTN_OFF] = ID_TEXTURE_UI_GAMEOVER_BTN_OFF;
	identifier[IDX_TXTR_UI_GAMEOVER_BTN_ON] = ID_TEXTURE_UI_GAMEOVER_BTN_ON;
	identifier[IDX_TXTR_UI_GAMEOVER_BTN2_OFF] = ID_TEXTURE_UI_GAMEOVER_BTN2_OFF;
	identifier[IDX_TXTR_UI_GAMEOVER_BTN2_ON] = ID_TEXTURE_UI_GAMEOVER_BTN2_ON;
	identifier[IDX_TXTR_UI_WIN_BG] = ID_TEXTURE_UI_WIN_BG;
	identifier[IDX_TXTR_UI_WIN_LABEL] = ID_TEXTURE_UI_WIN_LABEL;
	identifier[IDX_TXTR_UI_WIN_TROPHY] = ID_TEXTURE_UI_WIN_TROPHY;
	identifier[IDX_TXTR_UI_WIN_BTN_OFF] = ID_TEXTURE_UI_WIN_BTN_OFF;
	identifier[IDX_TXTR_UI_WIN_BTN_ON] = ID_TEXTURE_UI_WIN_BTN_ON;
}

static void	init_ui_identifier2(char **identifier)
{
	identifier[IDX_TXTR_UI_HOME_BG] = ID_TEXTURE_UI_HOME_BG;
	identifier[IDX_TXTR_UI_HOME_LBL] = ID_TEXTURE_UI_HOME_LBL;
	identifier[IDX_TXTR_UI_HOME_BTN1_OFF] = ID_TEXTURE_UI_HOME_BTN1_OFF;
	identifier[IDX_TXTR_UI_HOME_BTN1_ON] = ID_TEXTURE_UI_HOME_BTN1_ON;
	identifier[IDX_TXTR_UI_HOME_BTN2_OFF] = ID_TEXTURE_UI_HOME_BTN2_OFF;
	identifier[IDX_TXTR_UI_HOME_BTN2_ON] = ID_TEXTURE_UI_HOME_BTN2_ON;
	identifier[IDX_TXTR_UI_LVL_BG] = ID_TEXTURE_UI_LVL_BG;
	identifier[IDX_TXTR_UI_LVL_LBL] = ID_TEXTURE_UI_LVL_LBL;
	identifier[IDX_TXTR_UI_LVL_BTN1_OFF] = ID_TEXTURE_UI_LVL_BTN1_OFF;
	identifier[IDX_TXTR_UI_LVL_BTN1_ON] = ID_TEXTURE_UI_LVL_BTN1_ON;
	identifier[IDX_TXTR_UI_LVL_BTN2_OFF] = ID_TEXTURE_UI_LVL_BTN2_OFF;
	identifier[IDX_TXTR_UI_LVL_BTN2_ON] = ID_TEXTURE_UI_LVL_BTN2_ON;
	identifier[IDX_TXTR_UI_LVL_BTN3_OFF] = ID_TEXTURE_UI_LVL_BTN3_OFF;
	identifier[IDX_TXTR_UI_LVL_BTN3_ON] = ID_TEXTURE_UI_LVL_BTN3_ON;
	identifier[IDX_TXTR_UI_LVL_BTN4_OFF] = ID_TEXTURE_UI_LVL_BTN4_OFF;
	identifier[IDX_TXTR_UI_LVL_BTN4_ON] = ID_TEXTURE_UI_LVL_BTN4_ON;
	identifier[IDX_TXTR_UI_LVL_BTN5_OFF] = ID_TEXTURE_UI_LVL_BTN5_OFF;
	identifier[IDX_TXTR_UI_LVL_BTN5_ON] = ID_TEXTURE_UI_LVL_BTN5_ON;
	identifier[IDX_TXTR_UI_LVL_BTN_PREV_OFF] = ID_TEXTURE_UI_LVL_BTN_PREV_OFF;
	identifier[IDX_TXTR_UI_LVL_BTN_PREV_ON] = ID_TEXTURE_UI_LVL_BTN_PREV_ON;
}

void	init_identifier2(char **identifier)
{
	if (identifier == NULL)
		return ;
	init_weapons_identifier(identifier);
	init_hud_identifier(identifier);
	init_ui_identifier1(identifier);
	init_ui_identifier2(identifier);
}
