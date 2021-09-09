#pragma once


static inline void DSGM_UnlockSpritePalette(u8 screen) {
	switch(screen) {
		case DSGM_TOP:
			vramSetBankF(VRAM_F_LCD);
			break;
			
		case DSGM_BOTTOM:
			vramSetBankI(VRAM_I_LCD);
			break;
	}
}

static inline void DSGM_LockSpritePalette(u8 screen) {
	switch(screen) {
		case DSGM_TOP:
			vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);
			break;
			
		case DSGM_BOTTOM:
			vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);
			break;
	}
}

static inline u16 *DSGM_GetPaletteData(u8 screen, DSGM_Palette *palette) {
	return (screen == DSGM_TOP ? VRAM_F_EXT_SPR_PALETTE : VRAM_I_EXT_SPR_PALETTE)[palette->paletteNumber[screen]];
}

static inline int DSGM_NextFreePalette(u8 screen) {
	return DSGM_nextPalette[screen]++;
}

static inline bool DSGM_PaletteLoaded(u8 screen, DSGM_Palette *palette) {
	return palette->paletteNumber[screen] != DSGM_NO_PALETTE;
}

static inline bool DSGM_PaletteIsNitro(DSGM_Palette *palette) {
	return !palette->palette;
}
