#include "Entity.h"
#include "RenderContext.h"

Entity::Entity() {
	Pos = Vec3();
	Rotation = Quaternion();
	Show = false;
	ModelIdx = -1;
}

Entity::Entity(int modelIdx) {
	Pos = Vec3();
	Rotation = Quaternion();
	Show = true;
	ModelIdx = modelIdx;
}

Entity::Entity(int modelIdx, Vec3 pos) {
	Pos = pos;
	Rotation = Quaternion();
	Show = true;
	ModelIdx = modelIdx;
	ShaderProgram* program;
}

Entity::Entity(int modelIdx, Vec3 pos, Quaternion rotation) {
	Pos = pos;
	Rotation = rotation;
	Show = true;
	ModelIdx = modelIdx;
}

void Entity::Update(double time) {
	return;
}

void Entity::Render(void) {
}
