#pragma once

static inline void DSGM_SetTextLayer(u8 screen, u8 layerNumber) {
	DSGM_textLayer[screen] = layerNumber;
}

static inline void DSGM_SetTextColor(u8 screen, u16 color) {
	if(DSGM_text[screen][DSGM_textLayer[screen]].font.gfx == consoleGetDefault()->font.gfx) {
		(screen == DSGM_TOP ? BG_PALETTE : BG_PALETTE_SUB)[15 + (15 * 16)] = color;
	}
	else {
		(screen == DSGM_TOP ? BG_PALETTE : BG_PALETTE_SUB)[1] = color;
	}
}
