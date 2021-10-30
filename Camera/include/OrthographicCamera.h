#pragma once
#include "Vec3.h"
#include "Mat4.h"

class OrthographicCamera {
public:
	OrthographicCamera(float vertFOV, float near, float far, Vec3 pos, Vec3 up);
	void LookAt(Vec3 at);
	void SetPos(Vec3 pos);
	void Move(Vec3 dPos);
	void SetFOV(float fov);

	void SetOrthographic(float aspect);

	Mat4 ViewMat;
	Mat4 OrthographicMat;

private:
	float FOV;
	float Near;
	float Far;
	Vec3 Position;
	Vec3 Up;
};
