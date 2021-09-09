#pragma once

static inline void *DSGM_GetMeFromObjectInstanceRelationFull(DSGM_Room *room, DSGM_ObjectInstanceRelation *relation) {
	DSGM_Debug("Getting me value with group %d, ID %d\n", relation->groupN, relation->ID);
	return (void *)&room->objectGroups[relation->screen][relation->groupN].objectInstances[relation->ID];
}

static inline bool DSGM_StylusOverObjectInstanceFull(DSGM_Room *room, DSGM_ObjectInstance *me) {
	return DSGM_stylus.x >= me->x - room->view[me->screen].x && DSGM_stylus.x <= me->x - room->view[me->screen].x + DSGM_GetSpriteWidth(me->object->sprite) && DSGM_stylus.y >= me->y - room->view[me->screen].y && DSGM_stylus.y <= me->y - room->view[me->screen].y + DSGM_GetSpriteHeight(me->object->sprite);
}

static inline bool DSGM_ObjectInstanceOnScreenFull(DSGM_Room *room, DSGM_ObjectInstance *me) {	
	return ((!(me->x - room->view[me->screen].x >= 255)) && (!(me->y - room->view[me->screen].y >= 191))) &&\
	((!(me->x - room->view[me->screen].x <= -DSGM_GetSpriteWidth(me->object->sprite))) && (!(me->y - room->view[me->screen].y <= -DSGM_GetSpriteHeight(me->object->sprite)))) &&\
	!me->hide;
}

static inline bool (DSGM_ObjectInstanceCollision)(DSGM_ObjectInstance *me, DSGM_ObjectInstance *collider) {
	int w1 = DSGM_GetSpriteWidth(me->object->sprite);
	int w2 = DSGM_GetSpriteWidth(collider->object->sprite);
	int h1 = DSGM_GetSpriteHeight(me->object->sprite);
	int h2 = DSGM_GetSpriteHeight(collider->object->sprite);
	
	return ((collider->x > me->x - w2) && (collider->x < me->x + w1)) && ((collider->y > me->y - h2) && (collider->y < me->y + h1));
}

static inline int (DSGM_GetObjectInstanceRotset)(DSGM_ObjectInstance *me) {
	return me->angle - DSGM_rotations[me->screen];
}

static inline int DSGM_GetObjectInstanceIDFull(DSGM_Room *room, DSGM_ObjectInstance *me) {
	DSGM_ObjectInstance *group = DSGM_GetObjectGroupFull(room, me->screen, me->object)->objectInstances;
	return me - group;
}
