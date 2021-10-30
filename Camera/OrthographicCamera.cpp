#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(float vertFOV, float near, float far, Vec3 pos, Vec3 up) {
	FOV = vertFOV;
	Near = near;
	Far = far;
	Position = pos;
	Up = up;
}

void OrthographicCamera::LookAt(Vec3 at) {
	ViewMat = Mat4::LookAt(Position, at, Up);
}

void OrthographicCamera::SetPos(Vec3 pos) {
	Position = pos;
}

void OrthographicCamera::Move(Vec3 dPos) {
	Position += dPos;
}

void OrthographicCamera::SetFOV(float fov) {
	FOV = fov;
}

void OrthographicCamera::SetOrthographic(float aspect) {
	OrthographicMat = Mat4::Orthographic(aspect, FOV, Near, Far);
}