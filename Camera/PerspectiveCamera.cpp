#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(float vertFov, float near, float far, Vec3 pos, Vec3 up) {
	FOV = vertFov;
	Near = near;
	Far = far;
	Position = pos;
	Up = up;
}

void PerspectiveCamera::LookAt(Vec3 at) {
	ViewMat = Mat4::LookAt(Position, at, Up);
}

void PerspectiveCamera::SetPerspective(float aspect) {
	PerspectiveMat = Mat4::Perspective(aspect, FOV, Near, Far);
}

void PerspectiveCamera::Rotate(Quaternion rot) {
	Rotation = rot;
}

void PerspectiveCamera::SetPos(Vec3 pos) {
	Position = pos;
}

void PerspectiveCamera::Move(Vec3 dPos) {
	Position += dPos;
}

void PerspectiveCamera::SetFOV(float fov) {
	FOV = fov;
}