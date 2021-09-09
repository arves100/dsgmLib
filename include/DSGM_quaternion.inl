#pragma once

static inline Quaternion Quaternion_fromEuler(int32 roll, int32 pitch, int32 yaw) {
	//http://www.j3d.org/matrix_faq/matrfaq_latest.html#Q60
	/*Quaternion q = Quaternion_identity();
	Quaternion qt = Quaternion_identity();
	
	Quaternion qx = { cosLerp(pitch/2), sinLerp(pitch/2), 0, 0 };
	Quaternion qy = { cosLerp(yaw/2), 0, sinLerp(yaw/2), 0 };
	Quaternion qz = { cosLerp(roll/2), 0, 0, sinLerp(roll/2) };
	qt = Quaternion_multiplied(qx, qy);
	q = Quaternion_multiplied(qt, qz);
	
	return q;*/
	
	//http://content.gpwiki.org/index.php/OpenGL%3aTutorials%3aUsing_Quaternions_to_represent_rotation#Quaternion_from_Euler_angles
	Quaternion this;
	
	int32 p = pitch / 2;
	int32 y = yaw / 2;
	int32 r = roll / 2;
	
	int32 sinp = sinLerp(p);
	int32 siny = sinLerp(y);
	int32 sinr = sinLerp(r);
	int32 cosp = cosLerp(p);
	int32 cosy = cosLerp(y);
	int32 cosr = cosLerp(r);
	
	this.x = mulf32(mulf32(sinr, cosp), cosy) - mulf32(mulf32(cosr, sinp), siny);
	this.y = mulf32(mulf32(cosr, sinp), cosy) + mulf32(mulf32(sinr, cosp), siny);
	this.z = mulf32(mulf32(cosr, cosp), siny) - mulf32(mulf32(sinr, sinp), cosy);
	this.w = mulf32(mulf32(cosr, cosp), cosy) + mulf32(mulf32(sinr, sinp), siny);
	
	return this;
}
