#pragma once

static inline void DSGM_UseCamera(DSGM_Camera *camera) {
	//glLoadIdentity();
	gluLookAtf32(camera->position.x, camera->position.y, camera->position.z, camera->lookAt.x, camera->lookAt.y, camera->lookAt.z, camera->up.x, camera->up.y, camera->up.z);
}

static inline u64 DSGM_Distance3D(s32 x1, s32 y1, s32 z1, s32 x2, s32 y2, s32 z2) {
	s64 h = x1 - x2;
	s64 v = y1 - y2;
	s64 b = z1 - z2;
	return h * h + v * v + b * b;
}
