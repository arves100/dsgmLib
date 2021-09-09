#pragma once

static inline int DSGM_GetRoomNumberFull(DSGM_Room *rooms, DSGM_Room *room) {
	return room - rooms;
}
