#include "DataManager.h"

void DataManager::AddEntity(Entity entity) {
	Entities.push_back(entity);
}

void DataManager::AddModel(Model model) {
	Model newModel;
	newModel.numComponents = model.numComponents;
	for (int i = 0; i < model.numComponents; ++i) {
		ModelComponent newComp;
		newComp.Buffer_idx = -1;
		newComp.VBO_idx = -1;
		newComp.Material_idx = model.components[i].Material_idx;
		newModel.components.push_back(newComp);
	}
	Models.push_back(newModel);
}

void DataManager::AddMaterial(Importer::Material material) {
	Material newMaterial;
	Texture newTexture;
	newMaterial.d = material.d;
	newMaterial.illum = material.illum;
	newMaterial.Ka = material.Ka;
	newMaterial.Kd = material.Kd;
	newMaterial.Ke = material.Ke;
	newMaterial.Ks = material.Ks;
	newMaterial.name = material.name;
	newMaterial.Ni = material.Ni;
	newMaterial.Ns = material.Ns;

	// copy texture
	newTexture.channels = material.Kd_map.channels;
	newTexture.height = material.Kd_map.height;
	newTexture.width = material.Kd_map.width;
	newTexture.data = material.Kd_map.data;
	newMaterial.Kd_map = newTexture;
	Materials.push_back(newMaterial);
}

void DataManager::Update(double time) {
	for (int i = 0; i < Entities.size(); ++i) {
		Entities[i].Update(time);
	}
}