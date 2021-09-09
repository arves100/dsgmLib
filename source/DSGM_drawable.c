#include "DSGM.h"

void DSGM_InitDrawableBackground(DSGM_Layer *layer) {
	DSGM_Debug("Drawable background screen %d, layerNumber %d", layer->screen, layer->layerNumber);
	switch(layer->screen) {
		case DSGM_TOP:
			layer->vramId = bgInit(layer->layerNumber, BgType_Bmp16, BgSize_B16_256x256, layer->mapBase, layer->tileBase);
			break;
			
		case DSGM_BOTTOM:
			layer->vramId = bgInitSub(layer->layerNumber, BgType_Bmp16, BgSize_B16_256x256, layer->mapBase, layer->tileBase);
			break;
	}
}
