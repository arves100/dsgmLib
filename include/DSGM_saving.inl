#pragma once


// Saving applies to both saving and loading
static inline bool DSGM_StartSaving(void) {
	DSGM_save = fopen(DSGM_saveName, "r+b");
	return DSGM_save ? true : false;
}

static inline void DSGM_FinishSaving(void) {
	fclose(DSGM_save);
}
