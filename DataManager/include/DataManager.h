#pragma once
#include <vector>
#include "Entity.h"
#include "ModelData.h"
#include "OBJ_Importer.h"
#include "RenderContext.h"

/**
* The DataManager is strictly responsible for GPU data...
* This includes: 
*	Model data (verts/norms/texts),
*	Animation data (animation not implemented yet),
*	Material data
*/
class DataManager {
 public:
    DataManager(RenderContext* context);
	void AddEntity(Entity entity); // ~Maybe use? Not sure yet
	void AddModel(Model model);
	void AddMaterial(Importer::Material material);
	void Update(double time); // Unsure about an update as well
	void LoadFromImporter(Importer::OBJ_Importer& importer);
	void Render(unsigned int ModelIndex);

 private:
	// RenderContext allows for directly loading models to GPU
	// i.e. DataManager is the catalyst for adding data to the renderer
	// Still unsure about ingesting the context...thats okay for now
	RenderContext* RContext;
    std::vector<Entity> Entities;
    std::vector<Model> Models;
    std::vector<Material> Materials;
};
