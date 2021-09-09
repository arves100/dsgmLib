#pragma once

#define DSGM_3D_RENDERER (void *)3

#define DSGM_MATRIX_X 12
#define DSGM_MATRIX_Y 13
#define DSGM_MATRIX_Z 14

#define glVertex3fv(v) glVertex3f(v[0], v[1], v[2])
#define glNormal3fv(n) glNormal3f(n[0], n[1], n[2])

typedef struct {
	vect3D position;
	vect3D lookAt;
	vect3D up;
} DSGM_Camera;

void DSGM_InitStandard3D(void);

void DSGM_GetPositionMatrix(struct m4x4 *m);
vect3D DSGM_MatrixTranslationToVector(m4x4 initialMatrix, m4x4 resultantMatrix);

void DSGM_ApplyQuaternion(Quaternion *q);
void DSGM_ApplyInverseQuaternion(Quaternion *q);

void DSGM_DrawCube(float x, float y, float z, float width, float height, float depth);
