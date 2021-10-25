#include "OpenGLContext.h"
#include "RenderContext.h"
#include "Config.h"

RenderContext::RenderContext() {
#ifdef OPENGL
	OpenGL::GLFWInit();
#endif
	currentWindow = NULL;
}

RenderContext::~RenderContext(void) {
#ifdef OPENGL
	OpenGL::DestroyContext();
#endif
}

void RenderContext::Init(Window* window) {
	OpenGL::SetCurrentContext((GLFWwindow*)window->window);
	OpenGL::GLEWInit();
	OpenGL::SetGLFWSwap(1);

	buffers.resize(OpenGL::VERT_TEXTURE_NORMAL + 1);
	for (int i = 0; i <= OpenGL::VERT_TEXTURE_NORMAL; ++i) {
		buffers[i].type = (OpenGL::BufferType)i;
		buffers[i].VAO_ID = 0;
		OpenGL::GenVAOs(&(buffers[i].VAO_ID));
		OpenGL::InitVAO(buffers[i].VAO_ID, buffers[i].type);
	}
}

void RenderContext::SetCurrentWindow(Window* window) {
#ifdef OPENGL
	OpenGL::SetCurrentContext((GLFWwindow*)window->window);
	currentWindow = window;
#endif
}

void RenderContext::PollEvents(void) {
#ifdef OPENGL
	OpenGL::PollEvents();
#endif
}

void RenderContext::ClearBuffers(void) {
#ifdef OPENGL
	OpenGL::ClearColorBuffer();
	OpenGL::ClearDepthBuffer();
#endif
}

void RenderContext::LoadImportedData(Importer::OBJ_Importer& importer, DataManager& dataManager) {
	Importer::Data data = importer.InterleaveData();
	Importer::Model model;
	Importer::ModelComponent component;
	Model model_DM;
	ModelComponent component_DM;
	OpenGL::BufferType type = OpenGL::NONE;
	unsigned int* VBO_ID = NULL;
	for (int i = 0; i<importer.Models.size(); ++i) {
		model = importer.Models[i];
		model_DM.numComponents = 0;
		model_DM.components.clear();
		for (int j = 0; j < model.numComponents; ++j) {
			component = model.components[j];
			OpenGL::BindVAO(buffers[component.type].VAO_ID);
			buffers[component.type].VBO_IDs.push_back(0);
			VBO_ID = &buffers[component.type].VBO_IDs.back();
			OpenGL::GenVBOs(VBO_ID);
			OpenGL::BindVBO(*VBO_ID);
			OpenGL::BufferData(component.totalNumPoints*sizeof(float), 
							   &data.buffers[component.type][component.interleaveDataIndex]);

			component_DM.VBO_idx = *VBO_ID;
			component_DM.Buffer_idx = int(type);
			component_DM.Material_idx = component.materialIndex;
			++model_DM.numComponents;
			model_DM.components.push_back(component_DM);
		}
		dataManager.AddModel(model_DM);
	}

	for (int k = 0; k < importer.Materials.size(); ++k) {
		dataManager.AddMaterial(importer.Materials[k]);
	}
}

void RenderContext::Render(void) {
	OpenGL::ClearGLBuffers();
}

double RenderContext::GetTime(void) {
#ifdef OPENGL
	return OpenGL::GetTime();
#endif
}
/*
void RenderContext::LoadModelData(float* verts, size_t numVerts, BufferType buffType) {
#ifdef OPENGL
	unsigned int bufferSize = 0;
	switch(buffType) {
	case VERT:
		bufferSize = buffers[VERT].IDs.size();
		buffers[VERT].IDs.resize(bufferSize + 1);
		OpenGL::GenVBOs(&buffers[VERT].IDs[bufferSize], 1);
		break;

	case TEXTURE:
		bufferSize = buffers[VERT].IDs.size();
		buffers[VERT].IDs.resize(bufferSize + 1);
		OpenGL::GenVBOs(&buffers[VERT].IDs[bufferSize], 1);
		break;

	case NORMAL:
		break;

	case VERT_TEXTURE:
		break;

	case VERT_NORMAL:
		break;

	case VERT_TEXTURE_NORMAL:
		break;

	default:
		break;
	}
#endif
}
*/
