#pragma once

static inline void DSGM_RenderModelInstance(DSGM_ModelInstance *mi) {
	if(mi->interpolate) DSGM_RenderModelFrameInterp(mi->currentFrame, mi->nextFrame, mi->interpCounter, mi->fixTransformations, mi->model);
	else DSGM_RenderModelFrame(mi->currentFrame, mi->model);
}
