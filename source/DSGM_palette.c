#include "DSGM.h"

int DSGM_nextPalette[2] = { 0, 0 };

void DSGM_ClearPalettes(DSGM_Palette *palettes, int paletteCount) {
	int i;
	
	DSGM_nextPalette[DSGM_TOP] = 0;
	DSGM_nextPalette[DSGM_BOTTOM] = 0;
	
	for(i = 0; i < paletteCount; i++) {
		palettes[i].paletteNumber[DSGM_TOP] = DSGM_NO_PALETTE;
		palettes[i].paletteNumber[DSGM_BOTTOM] = DSGM_NO_PALETTE;
	}
}

void DSGM_LoadPaletteFull(u8 screen, DSGM_Palette *palette) {
	DSGM_UnlockSpritePalette(screen);
	palette->paletteNumber[screen] = DSGM_NextFreePalette(screen);
	if(DSGM_PaletteIsNitro(palette)) {
		if(screen == DSGM_TOP) DSGM_ReadFileManual(VRAM_F_EXT_SPR_PALETTE[palette->paletteNumber[screen]], 0, DSGM_AUTO_LENGTH, palette->nitroFilename);
		if(screen == DSGM_BOTTOM) DSGM_ReadFileManual(VRAM_I_EXT_SPR_PALETTE[palette->paletteNumber[screen]], 0, DSGM_AUTO_LENGTH, palette->nitroFilename);
	}
	else {
		if(screen == DSGM_TOP) dmaCopy(palette->palette, VRAM_F_EXT_SPR_PALETTE[palette->paletteNumber[screen]], *palette->paletteLength);
		if(screen == DSGM_BOTTOM) dmaCopy(palette->palette, VRAM_I_EXT_SPR_PALETTE[palette->paletteNumber[screen]], *palette->paletteLength);
	}
	DSGM_LockSpritePalette(screen);
}
