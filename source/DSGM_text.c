#include "DSGM.h"

PrintConsole DSGM_text[2][4];
int DSGM_textLayer[2];

void DSGM_InitText(DSGM_Layer *layer) {
	DSGM_Debug("Init text: screen %d, layerNumber %d, vramId %d\n", layer->screen, layer->layerNumber, DSGM_text[layer->screen][layer->layerNumber].bgId);
	
	ConsoleFont font;
	
	if(layer->background != DSGM_DEFAULT_FONT) {
		font.gfx = bgGetGfxPtr(layer->vramId);
		
		DSGM_UnlockBackgroundPalette(layer->screen);
		font.pal = (u16 *)&(layer->screen == DSGM_TOP ? VRAM_E_EXT_PALETTE : VRAM_H_EXT_PALETTE)[layer->layerNumber][0];
		font.numColors = 2;
		
		font.numChars = 127;
		font.bpp = 4;
		font.asciiOffset = 0;
		font.convertSingleColor = false;
	}
	
	consoleInit(&DSGM_text[layer->screen][layer->layerNumber], layer->layerNumber, BgType_Text4bpp, BgSize_T_256x256, layer->mapBase, layer->tileBase, layer->screen, layer->background == DSGM_DEFAULT_FONT);
	layer->vramId = DSGM_text[layer->screen][layer->layerNumber].bgId;
	
	if(layer->background != DSGM_DEFAULT_FONT) {
		consoleSetFont(&DSGM_text[layer->screen][layer->layerNumber], &font);
		DSGM_LockBackgroundPalette(layer->screen);
	}
	
	DSGM_textLayer[layer->screen] = layer->layerNumber;
	consoleSelect(&DSGM_text[layer->screen][layer->layerNumber]);
	consoleClear();
}

void DSGM_ClearText(u8 screen) {
	consoleSelect(&DSGM_text[screen][DSGM_textLayer[screen]]);
	consoleClear();
}

void DSGM_DrawText(u8 screen, int x, int y, const char *format, ...) {
	consoleSelect(&DSGM_text[screen][DSGM_textLayer[screen]]);
	DSGM_text[screen][DSGM_textLayer[screen]].cursorX = x;
	DSGM_text[screen][DSGM_textLayer[screen]].cursorY = y;
	
	va_list arg;
	va_start(arg, format);
	vfprintf(stdout, format, arg);
	va_end(arg);
}

void DSGM_BoxText(u8 screen, u8 x, u8 y, u8 width, u8 height, u8 delay, const char *format, ...) {
	char text[1024];
	va_list args;
	va_start(args, format);
	vsnprintf(text, 1023, format, args);
	va_end(args);
	
	int i;
	int len = strlen(text);
	u8 dx = x;
	u8 dy = y;
	
	consoleSelect(&DSGM_text[screen][DSGM_textLayer[screen]]);
	
	//consoleSetWindow(&DSGM_text[screen][DSGM_textLayer[screen]], x, y, width, height);
	
	for(i = 0; i < len; i++) {
		DSGM_text[screen][DSGM_textLayer[screen]].cursorX = dx;
		DSGM_text[screen][DSGM_textLayer[screen]].cursorY = dy;
		printf("%c", text[i]);
		
		dx += 1;
		
		if(text[i] == '\n' || (text[i] == ' ' && DSGM_GetWordLength(text + i + 1) + (dx - x) >= width && (dx - x) > 0)) {
			dx = x;
			dy += 1;
		}
		
		DSGM_Delay(delay);
	}
}
