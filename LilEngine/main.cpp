#include <iostream>
#include "Logger.h"
#include "RenderContext.h"
#include "OBJ_Importer.h"
#include "DataManager.h"
#include "Entity.h"
#include "Vec3.h"
#include "ShaderHandler.h"

int main() {
	Logger::InitLog("test.log");
	Importer::OBJ_Importer Importer = Importer::OBJ_Importer("../../ObjModels/",
								 "../../ObjModels/");
	Importer.ReadFile("test_texture.obj");


	RenderContext context = RenderContext();
	DataManager dataManager;
	Window window = Window(400, 400, "main");
	context.Init(&window);

	// Load shaders
	shaderHandler.MakeProgramFromSource("../Shaders/basic_vert.glsl",
					    "../Shaders/basic_frag.glsl",
					    "basic");
	shaderHandler.MakeActive("basic");

	// Load data into context
	context.LoadImportedData(Importer, dataManager);
	Entity test_entity(0, Vec3(0, 0, -2));
	dataManager.AddEntity(test_entity);

	while (!window.WindowClosed()) {
		context.ClearBuffers();
		window.SwapBuffers();
		context.PollEvents();
		dataManager.Update(context.GetTime());
		context.Render();
	}

	return 0;
}
