#pragma once
#include <vector>
#include <string>
#include "Vec3.h"

struct ModelComponent {
	int Buffer_idx;
	int VBO_idx;
	int Material_idx;
};

struct Model {
	int numComponents;
	std::vector<ModelComponent> components;
};

struct Texture {
	int width;
	int height;
	int channels;
	std::vector<unsigned char> data;
};

struct Material {
	std::string name;
	float Ns;
	Vec3  Ka;
	Vec3  Kd;
	Vec3  Ks;
	Vec3  Ke;
	float Ni;
	float d;
	float illum;
	Texture Kd_map;
};
