#pragma once

static inline int DSGM_GetBrightness(u8 screen) {
	int v = (screen == DSGM_TOP ? REG_MASTER_BRIGHT : REG_MASTER_BRIGHT_SUB);
	return (v - (v & 1 << 14)) < 16 ? (v - (v & 1 << 14)) : -(v - (v & 2 << 14));
}

static inline u64 DSGM_SquareDistance(s32 x1, s32 y1, s32 x2, s32 y2) {
	s64 h = x1 - x2;
	s64 v = y1 - y2;
	return h * h + v * v;
}

static inline u64 DSGM_Distance(s32 x1, s32 y1, s32 x2, s32 y2) {
	s64 h = x1 - x2;
	s64 v = y1 - y2;
	return sqrt32(h * h + v * v);
}

static inline u16 DSGM_GetAngle(s32 startx, s32 starty, s32 targetx, s32 targety) {
	u16 angle = 0;
	u16 anglerot = 180 << 6;
	
	while(anglerot > 5 << 6) {
		angle = DSGM_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
		anglerot = (anglerot - ((3 * anglerot) >> 3));
	}
	
	anglerot = 4 << 6;
	angle = DSGM_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
	anglerot = 2 << 6;
	angle = DSGM_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
	anglerot = 1 << 6;
	angle = DSGM_AdjustAngle(angle, anglerot, startx, starty, targetx, targety);
	
	return angle;
}

static inline int DSGM_Random(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
