#pragma once

static inline int DSGM_LargeBackgroundSizeToPixels(DSGM_LARGE_BACKGROUND_SIZES size) {
	return (size + 1) * 256;
}
