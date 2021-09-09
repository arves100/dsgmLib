#pragma once

#define DSGM_RealSin(a) fixedToFloat(sinLerp(a), 12)
#define DSGM_RealCos(a) fixedToFloat(cosLerp(a), 12)
#define DSGM_SetBrightness(screen, brightness) setBrightness((-screen) + 2, brightness)

void DSGM_FadeIn(u8 screen, u8 delay);
void DSGM_FadeOutToBlack(u8 screen, u8 delay);
void DSGM_FadeOutToWhite(u8 screen, u8 delay);

void DSGM_Delay(unsigned int time);

size_t DSGM_GetWordLength(char *text);

bool DSGM_Intersection(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy);

u16 DSGM_AdjustAngle(u16 angle, s16 anglerot, s32 startx, s32 starty, s32 targetx, s32 targety);
