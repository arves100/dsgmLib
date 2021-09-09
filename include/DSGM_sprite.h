#pragma once

#define DSGM_NO_SPRITE NULL

#define DSGM_FORM_RAM_SPRITE(sprite, palette, size, frames)\
{ (u8 *)&sprite##_Sprite_bin, (u32 *)&sprite##_Sprite_bin_size, NULL, &DSGM_Palettes[palette], size, frames, NULL }

#define DSGM_FORM_NITRO_SPRITE(sprite, palette, size, frames)\
{ NULL, 0, #sprite "_Sprite.bin", &DSGM_Palettes[palette], size, frames, NULL }

#define DSGM_FORM_FAT_SPRITE(sprite, palette, size, frames)\
{ NULL, 0, "fat:/" #sprite "_Sprite.bin", &DSGM_Palettes[palette], size, frames, NULL }

typedef struct {
	u8 *tiles;
	u32 *tilesLength;
	char *nitroFilename;
	DSGM_Palette *palette;
	SpriteSize size;
	u8 frames;
	
	u16 **topTiles;
	u16 **bottomTiles;
} DSGM_Sprite;

typedef struct {
	u8 width;
	u8 height;
} DSGM_Size;

typedef struct {
	int x;
	int y;
} DSGM_Scale;

// Originally from libnds' sprite.h; adapted to avoid naming conflicts
typedef union {
	struct {
		struct {
			u16 absoluteY					:8;	/**< Sprite Y position as displayed. */
			union {
				struct {
					u8 						:1;
					bool isHidden 			:1;	/**< Sprite is hidden (isRotoscale cleared). */
					u8						:6;
				};
				struct {
					bool isRotateScale		:1;	/**< Sprite uses affine parameters if set. */
					bool isSizeDouble		:1;	/**< Sprite bounds is doubled (isRotoscale set). */
					ObjBlendMode blendMode	:2;	/**< Sprite object mode. */
					bool isMosaic			:1;	/**< Enables mosaic effect if set. */
					ObjColMode colorMode	:1;	/**< Sprite color mode. */
					ObjShape shape			:2;	/**< Sprite shape. */
				};
			};
		};
		
		union {
			struct {
				u16 absoluteX				:9;	/**< Sprite X position as displayed. */
				u8 							:7;
			};
			struct {
				u8							:8;
				union {
					struct {
						u8					:4;
						bool hFlip			:1; /**< Flip sprite horizontally (isRotoscale cleared). */
						bool vFlip			:1; /**< Flip sprite vertically (isRotoscale cleared).*/
						u8					:2;
					};
					struct {
						u8					:1;
						u8 rotationIndex	:5; /**< Affine parameter number to use (isRotoscale set). */
						ObjSize size		:2; /**< Sprite size. */
					};
				};
			};
		};
		
		struct {
			u16 gfxIndex					:10;/**< Upper-left tile index. */
			ObjPriority priority			:2;	/**< Sprite priority. */
			u8 palette						:4;	/**< Sprite palette to use in paletted color modes. */
		};
		
		u16 attribute3;							/* Unused! Four of those are used as a sprite rotation matrice */
	};
	
	struct {
		uint16 attribute[3];
		uint16 filler;
	};
} DSGM_SpriteEntry;

extern int DSGM_nextFreeSprite[2];
extern int DSGM_rotsetTracker[2][32];

extern int DSGM_rotations[2][32];
extern DSGM_Scale DSGM_scales[2][32];

extern const DSGM_Size DSGM_Sizes[3][4];

void DSGM_ResetSprites(DSGM_Sprite *sprites, int spriteCount);

void DSGM_LoadSpriteFull(u8 screen, DSGM_Sprite *sprite);

void DSGM_CreateSprite(u8 screen, int spriteNumber, int x, int y, ObjPriority priority, int frame, bool hFlip, bool vFlip, DSGM_Sprite *sprite);

void DSGM_SetRotset(u8 screen, int rotset, int angle, int scaleX, int scaleY);

//u16 DSGM_GetSpriteColor(DSGM_Sprite *sprite, int frame, int x, int y);
