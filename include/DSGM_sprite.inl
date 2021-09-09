#pragma once

static inline int DSGM_NextFreeSpriteNumber(u8 screen) {
	return DSGM_nextFreeSprite[screen]++;
}

static inline int DSGM_NextFreeRotset(u8 screen) {
	int i;
	for(i = 0; i < 32; i++) {
		if(DSGM_rotsetTracker[screen][i] == 0) {
			return i;
		}
	}
	return 0;
}

static inline int DSGM_GetSpriteWidth(DSGM_Sprite *sprite) {
	switch(sprite->size) {
		case SpriteSize_8x8: return 8;
		case SpriteSize_16x16: return 16;
		case SpriteSize_32x32: return 32;
		case SpriteSize_64x64: return 64;
		case SpriteSize_16x8: return 16;
		case SpriteSize_32x8: return 32;
		case SpriteSize_32x16: return 32;
		case SpriteSize_64x32: return 64;
		case SpriteSize_8x16: return 8;
		case SpriteSize_8x32: return 8;
		case SpriteSize_16x32: return 16;
		case SpriteSize_32x64: return 32;
		default: return 0;
	}
	//u16 atr0 = SPRITE_SIZE_SHAPE(sprite->size);
	//u16 atr1 = SPRITE_SIZE_SIZE(sprite->size);
	//return DSGM_Sizes[atr0][atr1].width;
}

static inline int DSGM_GetSpriteHeight(DSGM_Sprite *sprite) {
	switch(sprite->size) {
		case SpriteSize_8x8: return 8;
		case SpriteSize_16x16: return 16;
		case SpriteSize_32x32: return 32;
		case SpriteSize_64x64: return 64;
		case SpriteSize_16x8: return 8;
		case SpriteSize_32x8: return 8;
		case SpriteSize_32x16: return 16;
		case SpriteSize_64x32: return 32;
		case SpriteSize_8x16: return 16;
		case SpriteSize_8x32: return 32;
		case SpriteSize_16x32: return 32;
		case SpriteSize_32x64: return 64;
		default: return 0;
	}
	//u16 atr0 = SPRITE_SIZE_SHAPE(sprite->size);
	//u16 atr1 = SPRITE_SIZE_SIZE(sprite->size);
	//return DSGM_Sizes[atr0][atr1].height;
}

static inline bool DSGM_SpriteIsNitro(DSGM_Sprite *sprite) {
	return !sprite->tiles;
}

static inline bool DSGM_SpriteLoaded(u8 screen, DSGM_Sprite *sprite) {
	if(screen == DSGM_TOP) return sprite->topTiles != NULL;
	else return sprite->bottomTiles != NULL;
}
