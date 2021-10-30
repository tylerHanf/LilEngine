#pragma once
#include "Vec3.h"
#include "Quaternion.h"
#include "ShaderHandler.h"

class Entity {
public:
	Entity(void);
	Entity(int modelIdx);
	Entity(int modelIdx, Vec3 pos);
	Entity(int modelIdx, Vec3 pos, Quaternion rotation);

	void Update(double time);
	void Render(void);

private:
	Vec3 Pos;
	Quaternion Rotation;
	bool Show;
	int ModelIdx;
	ShaderProgram* shaderProgram;
	
};
