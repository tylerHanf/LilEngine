#pragma once

#include "OpenGLContext.h"
#include "OBJ_Importer.h"
#include "DataManager.h"
#include "Window.h"
#include <vector>

struct Buffer {
	OpenGL::BufferType type;
	unsigned int VAO_ID;
	std::vector<unsigned int> VBO_IDs;
};

class RenderContext {
public:
	RenderContext();
	~RenderContext(void);
	void Init(Window* window);
	void SetCurrentWindow(Window* window);
	void PollEvents(void);
	void ClearBuffers(void);
	// This should be used for loading data that was imported from a file
	void LoadImportedData(Importer::OBJ_Importer& importer, DataManager& dataManager);
	// This should be used for loading procedural data
	void LoadModelData(float* verts, size_t numVerts, OpenGL::BufferType buffType);
	double GetTime(void);
	void Render();

	/*
		TODO: Find a way to manage buffers effectively-i.e. make changes to game objects not tedious
	*/

private:
	std::vector<Buffer> buffers;
	Window* currentWindow;
};
