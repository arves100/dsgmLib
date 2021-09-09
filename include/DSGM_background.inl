#pragma once

static inline void DSGM_UnlockBackgroundPalette(u8 screen) {
	switch(screen) {
		case DSGM_TOP:
			vramSetBankE(VRAM_E_LCD);
			break;
			
		case DSGM_BOTTOM:
			vramSetBankH(VRAM_H_LCD);
			break;
	}
}

static inline void DSGM_LockBackgroundPalette(u8 screen) {
	switch(screen) {
		case DSGM_TOP:
			vramSetBankE(VRAM_E_BG_EXT_PALETTE);
			break;
			
		case DSGM_BOTTOM:
			vramSetBankH(VRAM_H_SUB_BG_EXT_PALETTE);
			break;
	}
}

static inline unsigned short *DSGM_GetBackgroundPalette(u8 screen, int layerNumber) {
	return (screen == DSGM_TOP ? VRAM_E_EXT_PALETTE : VRAM_H_EXT_PALETTE)[layerNumber][0];
}

static inline void DSGM_SetScreenColor(u8 screen, u16 color) {
	switch(screen) {
		case DSGM_TOP:
			BG_PALETTE[0] = color;
			break;
			
		case DSGM_BOTTOM:
			BG_PALETTE_SUB[0] = color;
			break;
	}
}

static inline bool DSGM_BackgroundIsNitroFull(DSGM_Background *background) {
	return !background->tiles;
}

static inline unsigned int DSGM_GetLayerPriorityFull(DSGM_Layer *layer) {
	return (unsigned int)bgGetPriority(layer->vramId);
}

static inline void DSGM_SetLayerPriorityFull(DSGM_Layer *layer, unsigned int priority) {
	bgSetPriority(layer->vramId, priority);
}

static inline BgSize DSGM_GetBGSize(u8 screen, int layerNumber) {
	return bgState[layerNumber + ((screen == DSGM_BOTTOM) * 4)].size;
}

static inline u16 DSGM_GetTileFull(DSGM_Layer *layer, int x, int y) {
	u16 *map;
	if(layer->background->type == DSGM_LARGE_BACKGROUND) {
		map = layer->largeBackgroundMap;
	}
	else {
		map = bgGetMapPtr(layer->vramId);
	}
	
	// todo: optimise with div and modulus rather than loop
	while(y > 31) {
		y -= 32;
		x += 64;
	}
	while(x > 31) {
		x -= 32;
		y += 32;
	}
	
	// DSGM_GetBGWidth(layer->screen, layer->layerNumber)
	return map[y * 32 + x];
}

static inline void DSGM_SetTileFull(DSGM_Layer *layer, int x, int y, u16 tile) {
	u16 *map;
	if(layer->background->type == DSGM_LARGE_BACKGROUND) {
		map = layer->largeBackgroundMap;
	}
	else {
		map = bgGetMapPtr(layer->vramId);
	}
	
	while(y > 31) {
		y -= 32;
		x += 64;
	}
	while(x > 31) {
		x -= 32;
		y += 32;
	}
	
	map[y * 32 + x] = tile;
}

static inline void DSGM_SetTileForceVRAM(DSGM_Layer *layer, int x, int y, u16 tile) {
	u16 *map = bgGetMapPtr(layer->vramId);
	
	if(layer->background->type == DSGM_LARGE_BACKGROUND) {
		x %= 512 / 8;
		y %= 512 / 8;
	}
	
	while(y > 31) {
		y -= 32;
		x += 64;
	}
	while(x > 31) {
		x -= 32;
		y += 32;
	}
	
	map[y * DSGM_GetBGWidth(layer->screen, layer->layerNumber) / 16 + x] = tile;
}

static inline void DSGM_SetRotationCenterFull(DSGM_Layer *layer, int x, int y) {
	bgSetCenter(layer->vramId, x, y);
}

static inline void DSGM_RotateBackgroundFull(DSGM_Layer *layer, int angle) {
	bgSetRotate(layer->vramId, angle);
}

static inline void DSGM_ScaleBackgroundFull(DSGM_Layer *layer, int x, int y) {
	bgSetScale(layer->vramId, x, y);
}
