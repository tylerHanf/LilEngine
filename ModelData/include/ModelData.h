#pragma once
#include <vector>
#include <string>
#include "Vec3.h"

struct ModelComponent {
	unsigned int Buffer_idx;
	unsigned int VBO_idx;
	unsigned int Material_idx;
	unsigned int Shader_idx;
	unsigned int NumPoints; // Total number of floats in the component
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
