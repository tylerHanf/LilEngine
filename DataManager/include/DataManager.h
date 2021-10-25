#pragma once
#include <vector>
#include "Entity.h"
#include "ModelData.h"
#include "OBJ_Importer.h"

class DataManager {
public:
	void AddEntity(Entity entity);
	void AddModel(Model model);
	void AddMaterial(Importer::Material material);
	void Update(double time);

private:
	std::vector<Entity> Entities;
	std::vector<Model> Models;
	std::vector<Material> Materials;
};
