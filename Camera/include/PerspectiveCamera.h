#pragma once
#include "Vec3.h"
#include "Mat4.h"
#include "Quaternion.h"

class PerspectiveCamera {
public:
	PerspectiveCamera(float vertFov, float near, float far, Vec3 pos, Vec3 up);
	void LookAt(Vec3 at);
	void Rotate(Quaternion rot);
	void SetPos(Vec3 pos);
	void Move(Vec3 dPos);
	void SetFOV(float fov);

	void SetPerspective(float aspect);

	Mat4 ViewMat;
	Mat4 PerspectiveMat;
private:
	float FOV;
	float Near;
	float Far;
	Vec3 Position;
	Vec3 Up;
	Quaternion Rotation;
};
