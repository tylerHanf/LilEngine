#include "DataManager.h"

DataManager::DataManager(RenderContext* renderContext) {
	RContext = renderContext;
}

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

void DataManager::LoadFromImporter(Importer::OBJ_Importer& importer) {
  Importer::Model I_model;
  Importer::ModelComponent I_component;
  Model model;
  model.numComponents = 0;
  ModelComponent component;

  Importer::Data data = importer.InterleaveData();

  // Load models, let renderer generate and populate as needed
  for (int i=0; i<importer.NumModels(); ++i) {
    I_model = importer.Models[i];

	// Faster to resize ahead of time
	model.components.resize(I_model.numComponents);

	// Iterate through all components of model and add them
    for (int j=0; j<I_model.numComponents; ++j) {
      I_component = I_model.components[j];
      component.VBO_idx = 0;
      component.Buffer_idx = int(I_component.type);
      component.Material_idx = I_component.materialIndex;
	  component.Shader_idx = 0;
	  component.NumPoints = I_component.totalNumPoints;

	  // Load data in GPU
	  RContext->LoadData(&data.buffers[I_component.type][I_component.interleaveDataIndex],
						  I_component.totalNumPoints * sizeof(float),
						  (OpenGL::BufferType)I_component.type,
						  &component.Buffer_idx);

	  // Add component to model
      ++model.numComponents;
      model.components[j] = component;
    }
	// Add model to model buffer
	Models.push_back(model);
  }

  // Add materials
  for (int k=0; k<importer.Materials.size(); ++k) {
    AddMaterial(importer.Materials[k]);
  }
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
