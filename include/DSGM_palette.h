#pragma once

#define DSGM_NO_PALETTE -1

#define DSGM_GetPalette(palette)\
DSGM_Palettes[palette]

#define DSGM_FORM_RAM_PALETTE(palette)\
{ (u8 *)&palette##_Pal_bin, (u32 *)&palette##_Pal_bin_size, NULL, { DSGM_NO_PALETTE, DSGM_NO_PALETTE } }

#define DSGM_FORM_NITRO_PALETTE(palette)\
{ NULL, 0, #palette "_Pal.bin", { DSGM_NO_PALETTE, DSGM_NO_PALETTE } }

#define DSGM_FORM_FAT_PALETTE(palette)\
{ NULL, 0, "fat:/" #palette "_Pal.bin", { DSGM_NO_PALETTE, DSGM_NO_PALETTE } }

typedef struct {
	u8 *palette;
	u32 *paletteLength;
	char *nitroFilename;
	
	int paletteNumber[2];
} DSGM_Palette;

extern int DSGM_nextPalette[2];

void DSGM_ClearPalettes(DSGM_Palette *palettes, int paletteCount);

void DSGM_LoadPaletteFull(u8 screen, DSGM_Palette *Palette);
